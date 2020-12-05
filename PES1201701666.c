#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int k1,int k2)
{
	if(k1 > k2)
		return k1;
	else
		return k2;
}
char* intal_add(char* intal1, char* intal2)
{
	int k1,k2;
	k1=strlen(intal1);
	k2=strlen(intal2);
	char *ans=(char*)malloc(sizeof(char)*1001);
	k1-=1;
	k2-=1;
	int i=0;
	int carry=0;
	int val_to_add;
	while(k1 >=0 && k2>=0)
	{
		int val=(intal1[k1]-'0')+(intal2[k2]-'0')+carry;
		if(val >= 10)
		{
			carry=1;
			val_to_add=val % 10;
		}
		else
		{
			carry=0;
			val_to_add=val;
		}
		ans[i]=(val_to_add+'0');
		i+=1;
		k1-=1;
		k2-=1;
	}
	while(k2 >= 0)
	{
		int val=(intal2[k2]-'0')+carry;
		if(val >= 10)
		{
			carry=1;
			val_to_add=val % 10;
		}
		else
		{
			carry=0;
			val_to_add=val;
		}
		ans[i]=(val_to_add+'0');
		i+=1;
		k2-=1;
	}
	while(k1 >=0)
	{
		int val=(intal1[k1]-'0')+carry;
		if(val >= 10)
		{
			carry=1;
			val_to_add=val % 10;
		}
		else
		{
			carry=0;
			val_to_add=val;
		}
		ans[i]=(val_to_add+'0');
		i+=1;
		k1-=1;
	}
	if(carry==1)
	{
		ans[i]='1';
		i+=1;
	}
	char *rev=(char*)malloc(sizeof(char)*1001);
	int j=0;
	for(int i=strlen(ans)-1;i>=0;i--)
	{
		rev[j]=ans[i];
		j+=1;
	}
	//free(ans);
	//ans=NULL;
	rev[j]='\0';
	return rev;
}

int intal_compare(char* intal1, char* intal2)
{
	int k1=strlen(intal1);
	int k2=strlen(intal2);
	if(k1 > k2)
		return 1;
	else if(k2 > k1)
		return -1;
	else
	{
		for(int i=0;i < k1;i++)
		{
			if((intal1[i]-'0') > (intal2[i]-'0'))
			{
				return 1;
			}
			else if((intal1[i]-'0') < (intal2[i]-'0'))
			{
				return -1;
			}
		}
	}
	return 0;
}
char* subtract(char* val1,char* val2,int k1,int k2)
{	
	char *check=(char*)malloc(sizeof(char)*10000);
	k1-=1;
	k2-=1;
	int i=0;
	int carry=0;
	while(k2 >=0)
	{
		int a=(val1[k1]-'0')-carry;
		//printf("%d\n",a);
		int b=val2[k2]-'0';
		//printf("%d\n",b);
		if(a > b){
			check[i]=(a-b)+'0';
			i+=1;
			carry=0;
		}
		else if(b > a)
		{
			check[i]=((a+10)-b)+'0';
			i+=1;
			carry=1;
		}
		else
		{
			check[i]=0+'0';
			i+=1;
			carry=0;
		}
		k1-=1;
		k2-=1;
		//printf("%s\n",check);
	}
	//printf("%s\n",check);
	while(k1 >= 0)
	{
		if(carry==1)
		{
			int a=(val1[k1]-'0')-carry;
			if(a==-1){
				a=9;
				carry=1;
				check[i]=a+'0';
				i+=1;
			}
			else
			{
				check[i]=a+'0';
				i+=1;
				carry=0;
			}
		}
		else
		{
			check[i]=val1[k1];
			i+=1;
		}
		k1-=1;
	}
	//printf("%s\n",check);
	int flag=0;
	char *final=(char*)malloc(sizeof(char)*1001);
	int j=0;
	for(i=strlen(check)-1;i>=0;i--)
	{
		if(check[i]!='0' && flag==0){
			flag=1;
			final[j]=check[i];
			j+=1;
		}
		else if(flag==1){
			final[j]=check[i];
			j+=1;
		}
	}
	//printf("%s\n",final);
	return final;
}
char* intal_diff(char* intal1, char* intal2)
{
	int val;
	val=intal_compare(intal1,intal2);
	char *re=(char*)malloc(sizeof(char)*1);
	if(val==0){
		strcpy(re,"0");
		return re;
	}
	else if(val==-1){
		int k1=strlen(intal1);
		int k2=strlen(intal2);
		return subtract(intal2,intal1,k2,k1);
	}
	else
	{
		int k1=strlen(intal1);
		int k2=strlen(intal2);
		return subtract(intal1,intal2,k1,k2);
	}
}
char* find_product(int k1,int k2,char *val1,char *val2)
{
	char *ans3=(char*)malloc(sizeof(char)*1001);
	char *result1=(char*)malloc(sizeof(char)*1001);
	k2-=1;
	int count=0;
	while(k2 >= 0){
		int j=0;
		int b=val2[k2]-'0';
		int carry=0;
		char *rev2=(char*)malloc(sizeof(char)*1001);
		char *dup=(char*)malloc(sizeof(char)*1001);
		for(int i=k1-1;i>=0;i--)
		{
			int a=val1[i]-'0';
			int prod=(a*b)+carry;
			char val_to_pro[2];
			val_to_pro[0]=(prod%10)+'0';
			carry=((prod)/10);
			//printf("%s %d \n",val1[i],strlen(val1)==k1);
			//printf("(%c %d %d) ",val_to_pro,a,a);
			dup[j]=val_to_pro[0];
			j+=1;
		}
		//printf("\n");
		if(carry){
			dup[j]=carry+'0';
			j+=1;
		}
		j=0;
		for(int i=strlen(dup)-1;i>=0;i--)
		{
			rev2[j]=dup[i];
			j+=1;
		}
		
		int temp=count;
		while(temp){
			rev2[j]='0';
			j+=1;
			temp-=1;
		}
		rev2[j]='\0';
		//printf("\n\n%s rt %lu \n\n",rev2,strlen(rev2) );
		if(count > 0){
			strcpy(result1,intal_add(ans3,rev2));
			strcpy(ans3,result1);
		}
		else
			strcpy(ans3,rev2);
		count+=1;
		k2-=1;
	}

	return ans3;

}
char* intal_multiply(char* intal1, char* intal2)
{
	int k1=strlen(intal1),k2=strlen(intal2);
	char *zero=(char*)malloc(sizeof(char)*2);
	if(strcmp(intal1,"0")==0 || strcmp(intal2,"0")==0)
	{
		strcpy(zero,"0");
		zero[1]='\0';
		return zero;
	}
	else if(k1 < k2)
	{	
		return find_product(k2,k1,intal2,intal1);
	}
	else
	{
		return find_product(k1,k2,intal1,intal2);
	}
}
char* find_divisor_2(char* val3)
{
	char *final_ans=(char*)malloc(sizeof(char)*1001);
	int *arr=(int*)malloc(sizeof(int)*6);
	arr[0]=10;
	arr[1]=12;
	arr[2]=14;
	arr[3]=16;
	arr[4]=18;
	int carry=0;
	int length=strlen(val3);
	int j=0;
	int val;
	for(int i=0;i < length;i++)
	{
		if(carry==0)
		{
			val=val3[i]-'0';
			carry=val % 2;
		}
		else
		{
			int val1=val3[i]-'0';
			carry=val1 % 2;
			val=arr[val1/2];

		}
		if(j!=0 || val/2!=0){
			final_ans[j]=(val/2)+'0';
			j+=1;
		}
	}
	final_ans[strlen(final_ans)]='\0';
	//printf("before mid %s %d %lu \n",final_ans,j,strlen(final_ans));
	return final_ans;
}
char* intal_mod(char* intal1, char* intal2)
{
	//printf("%s\n",intal1);
	//printf("%s\n",intal2 );
	char *zero=(char*)malloc(sizeof(char)*1001);
	char *ans6=(char*)malloc(sizeof(char)*1001);
	strcpy(ans6,intal1);
	if(strcmp(intal1,"0")==0 || strcmp(intal2,"0")==0)
	{
		strcpy(zero,"0");
		return zero;
	}
	if(intal_compare(intal1,intal2)==0){
			strcpy(zero,"0");
			return zero;
	}
	else if(intal_compare(intal1,intal2)==-1){
			return intal1;
	}
	else
	{
		//char *temp1=(char*)malloc(sizeof(char)*1001);
		/*while(intal_compare(ans6,intal2)!=-1)
		{
			strcpy(ans6,intal_diff(ans6,intal2));
		}
		15//2=7
		

		return ans6;*/
		//printf("Jkjkjk\n");
		char *left=(char*)malloc(sizeof(char)*1001);
		char *right=(char*)malloc(sizeof(char)*1001);
		char *multi=(char*)malloc(sizeof(char)*1001);
		char *differ=(char*)malloc(sizeof(char)*1001);
		strcpy(left,"1");
		strcpy(right,intal1);
		char *mid=(char*)malloc(sizeof(char)*1001);
		while(intal_compare(left,right)!=1)
		{	
			strcpy(mid,find_divisor_2(intal_add(left,right)));
			//printf("mid:%s\n",mid);
			strcpy(multi,intal_multiply(mid,intal2));
			//printf("multi:%s\n",multi);
			if(intal_compare(multi,intal1)==1)
			{
				strcpy(right,intal_diff(mid,"1"));
				//printf("right:%s\n",right);
			}
			else
			{
				strcpy(differ,intal_diff(multi,intal1));
				//printf("%s\n",differ);
				if(intal_compare(differ,intal2)!=1)
					return differ;
				else
				{
					strcpy(left,intal_add(mid,"1"));
					//printf("left:%s\n",left);
				}
			}

		}
		return differ;
	}
}
char* intal_pow(char* intal1, unsigned int n)
{
	char *hup=(char*)malloc(sizeof(char)*1);
	//char *sup=(char*)malloc(sizeof(char)*1);
	char *ans5=(char*)malloc(sizeof(char)*1001);
	//char *rev2=(char*)malloc(sizeof(char)*1000);
	if(n==0)
	{
		strcpy(hup,"1");
		return hup;
	}
	if(strcmp(intal1,"0")==0)
	{
		strcpy(hup,"0");
		return hup;
	}
	else
	{
		strcpy(ans5,"1");
		for(unsigned int i=0;i < n;i++)
		{
				strcpy(ans5,intal_multiply(ans5,intal1));
		}
		return ans5;
	}
}
char* find_gcd(char* intal1,char* intal2)
{
	if(strcmp(intal1,"0")==0)
		return intal2;
	return find_gcd(intal_mod(intal2,intal1),intal1);
}
char* intal_gcd(char* intal1, char* intal2)
{
	char *ans6=(char*)malloc(sizeof(char)*1001);
	char *hup=(char*)malloc(sizeof(char)*1);
	if(strcmp(intal2,"0")==0 || strcmp(intal1,"0")==0)
	{
		strcpy(hup,"0");
		return hup;
	}
	else
	{
		if(intal_compare(intal1,intal2) ==1)
		{
			strcpy(ans6,find_gcd(intal2,intal1));
			return ans6;
		}
		else
		{
			strcpy(ans6,find_gcd(intal1,intal2));
			return ans6;
		}
	}
}

char* intal_fibonacci(unsigned int n)
{
	char *arr1=(char*)malloc(sizeof(char)*1001);
	char *arr2=(char*)malloc(sizeof(char)*1001);
	char *arr3=(char*)malloc(sizeof(char)*1001);
	strcpy(arr1,"0");
	strcpy(arr2,"1");
	if(n < 2)
	{
		if(n==0)
			return arr1;
		else
			return arr2;
	}
	n-=2;
	for(unsigned int i=0;i <= n;i++){		
		strcpy(arr3,intal_add(arr1,arr2));
		strcpy(arr1,arr2);
		strcpy(arr2,arr3);
	}
	return arr3;

}
char* intal_factorial(unsigned int n)
{
	char *fact=(char*)malloc(sizeof(char)*1001);
	strcpy(fact,"1");
	if(n==0)
	{
		return fact;
	}
	for(unsigned int i=1;i <=n ;i++)
	{
		char *duplicate=(char*)malloc(sizeof(char)*1001);
		int j=0;
		long long int temp=i;
		while(temp > 0)
		{
			duplicate[j++]=(temp % 10)+'0';
			temp/=10;
		}
		j=0;
		char *reverse=(char*)malloc(sizeof(char)*1001);
		for(int k=strlen(duplicate)-1;k>=0;k--)
		{
			reverse[j++]=duplicate[k];
		}
		//printf("%s %s \n",reverse,fact );
		strcpy(fact,intal_multiply(fact,reverse));
	}
	return fact;
}
unsigned int min1(unsigned int a ,unsigned int b)
{
	if(a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
char* intal_bincoeff(unsigned int n, unsigned int k)
{
	char cof[k+1][1000];
	char *final_result=(char*)malloc(sizeof(char)*1001);
	for(unsigned int i=0;i < k+1;i++)
	{
		strcpy(cof[i],"0");
	}
	strcpy(cof[0],"1");
	for(unsigned int i=1;i <=n;i++)
	{
		for(unsigned int j=min1(i,k);j >0;j--)
		{
			strcpy(cof[j],intal_add(cof[j],cof[j-1]));
		}
	}
	strcpy(final_result,cof[k]);
	return final_result;
}
int intal_max(char **arr, int n)
{
	int index;
	char *max1=(char*)malloc(sizeof(char)*(1001));
	strcpy(max1,"0");
	for(int i=0;i < n;i++)
	{
		if(intal_compare(arr[i],max1)==1)
		{
			strcpy(max1,arr[i]);
			index=i;
		}
	}
	return index;
}
int intal_min(char **arr, int n)
{
	int index;
	char *min1=(char*)malloc(sizeof(char)*(1001));
	memset(min1,'9',1001);
	for(int i=0;i < n;i++)
	{
		if(intal_compare(arr[i],min1)==-1)
		{
			strcpy(min1,arr[i]);
			index=i;
		}
	}
	return index;
}
