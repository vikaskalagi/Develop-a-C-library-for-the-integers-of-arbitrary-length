#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* intal_add(const char* intal1, const char* intal2)
{
	char *result=malloc(sizeof(char)*1001);
	int c=0;
	int l1=strlen(intal1);
	int l2=strlen(intal2);
	int i=l1-1;
	int j=l2-1;
	int k=0;
	int a;
	while(i>-1 && j>-1)
	{	a=intal1[i--]-'0'+intal2[j--]-'0'+c;
		//result[k++]=a%10;
		sprintf(&result[k++], "%d", a%10); 
		c=a/10;
	}
	while(i>-1)
	{	a=intal1[i--]-'0'+c;
		sprintf(&result[k++], "%d", a%10);
		//result[k++]=a%10;
		c=a/10;
	}
	while(j>-1)
	{
		a=intal2[j--]-'0'+c;
		sprintf(&result[k++], "%d", a%10);
		//result[k++]=a%10;
		c=a/10;	
	}
	if(c)
	{
		sprintf(&result[k++], "%d", c);
		//result[k++]=c;
	}
	//printf("%s \n",result);
	for(int j=0;j<k/2;j++)
	{	int temp=result[j];
		result[j]=result[k-j-1];
		result[k-j-1]=temp;
	}
	//printf("%s \n",result);
	result[k]='\0';
	return result;
}

int intal_compare(const char* intal1, const char* intal2)
{
	int l1=strlen(intal1);
	int l2=strlen(intal2);
	if(l1>l2)return 1;
	if(l2>l1)return -1;
	//printf("%s %s \n",intal1,intal2);
	for (int i=0;i<l1;i++)
	{	//printf("%d %d \n",intal1[i]-'0' , intal2[i]-'0');
		if(intal1[i]-'0' > intal2[i]-'0')
			return 1;
		else if(intal1[i]-'0' < intal2[i]-'0')return -1;
	}
	return 0;
}

char* intal_diff(const char* intal1, const char* intal2)
{	//printf("df");
	char *result=malloc(sizeof(char)*1001);
	int c=0;
	//char *a=intal1;
	const char *a;
	const char *b;
	int indicate=intal_compare(intal1,intal2);
	if(indicate==0)
	{
		result[0]='0';
		result[1]='\0';
		//printf("%s er\n", result);
		return result;
	}
	else if(indicate==1)
	{
		a=intal1;
		b=intal2;
	}
	else
	{
		b=intal1;
		a=intal2;	
	}
	int l1=strlen(a);
	int l2=strlen(b);
	//printf("%d %d rtbn\n", l1,l2);
	int i=l1-1;
	int j=l2-1;
	int k=0;
	//printf("%c %c \n",a[i],b[j]);
	while(j>-1)
	{	
		if(a[i]-'0'-c>=(b[j]-'0'))
		{	//printf("%d %d %d %d 	er \n",a[i]-c-b[j],k,a[i]-'0'-c,(b[j]-'0'));
			result[k++]=a[i]-c-b[j]+'0';
			//sprintf(&result[k++], "%d", a[i]-c-b[j]);
			//result[k++]=a[i]-c-b[j];
			c=0;
		}
		else{
			//printf("%d %d %d %d 	\n",b[j]-'0'+c,((a[i]-'0')+10),k,((a[i]-'0')+10)-b[j]-'0'+c);
			result[k++]=((a[i]-'0')+10)-b[j]+'0'-c+'0';
			//sprintf(&result[k++], "%d", ((a[i]-'0')+10)-b[j]+'0'-c);
			//result[k++]=b[j]-'0'+c-((a[i]-'0')+10);
			c=1;
		}
		i--;
		j--;
	}
	while(i>-1)
	{//printf("%cr%d ",a[i],c);
		if(c)
		{	if(a[i]=='0')
			{
				result[k++]=a[i]-c+10;
				c=1;
				//printf("sdf");
			}
			else{
			result[k++]=a[i]-c;
			c=0;
		}
		}
		else
		{	result[k++]=a[i];
		}
		i--;
	}
	while(result[k-1]=='0')
		k--;
	
	for(int o=0;o<k/2;o++)
	{
		int temp=result[o];
		result[o]=result[k-o-1];
		result[k-o-1]=temp;
	}
	result[k]='\0';
	
	return result;
}

char* intal_multiply(const char* intal1, const char* intal2)
{
	int len1 = strlen(intal1); 
    int len2 = strlen(intal2); 
    if (len1 == 0 || len2 == 0) {
  	char *ft=malloc(sizeof(char)*2);
    ft[0]='0';
    ft[1]='\0';
    return ft; }
  
    char *result=calloc(sizeof(char),(len1 + len2+1)); 
  	  
    int i_n1 = 0;  
    int i_n2 = 0;  
    
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = intal1[i] - '0'; 
  
         
        i_n2 = 0;  
          
          
        for (int j=len2-1; j>=0; j--) 
        { 
           
            int n2 = intal2[j] - '0'; 
  
  
            int sum ; 
            if(result[i_n1+i_n2]>='0' && result[i_n1+i_n2]<='9')
            sum = n1*n2 + result[i_n1 + i_n2] -'0'+ carry; 
  			else
  				sum = n1*n2 + carry;
  			
            carry = sum/10; 
  
             result[i_n1 + i_n2]=sum%10+'0';
          
  			
            i_n2++; 
        } 
        if(carry > 0)
        { 
        	if(result[i_n1+i_n2]>='0' && result[i_n1+i_n2]<='9')
        	sprintf(&result[i_n1 + i_n2], "%d", result[i_n1 + i_n2]+carry-'0');
        	else
        		sprintf(&result[i_n1 + i_n2], "%d", carry);
  		}
  		
        i_n1++; 
    } 
  
  
    int le = strlen(result) - 1;
    int i=le; 
    while (i>=0 && result[i] == '0') 
    i--; 
    if (i == -1) 
    {
   result[0]='0';
   result[1]='\0';
   return result;
    }
    int o=0; 
    le++;

	while(o<le/2)
	{
		char temp=result[o];
		result[o]=result[le-o-1];
		result[le-o-1]=temp;
		o++;
	}
	result[le]='\0';
    return result; 
}

static char* divide_by_two(char* val3)
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
			j++;
		}
	}
	final_ans[j]='\0';
	//printf("before mid %s %d %lu \n",final_ans,j,strlen(final_ans));
	free(arr);
	return final_ans;
}
char* intal_mod(const char* intal1, const char* intal2)
{
	//printf("%s\n",intal1);
	//printf("%s\n",intal2 );
	//char *zero=(char*)malloc(sizeof(char)*1001);
	char *ans6=(char*)malloc(sizeof(char)*1001);
	char *result=(char*)malloc(sizeof(char)*1001);
	strcpy(ans6,intal1);
	int z=intal_compare(intal1,intal2);
	if(strcmp(intal1,"0")==0 || z==0)
	{
		result[0]='0';
		result[1]='\0';
		return result;
	}
	else if(z==-1){
		strcpy(result,intal1);
			return result;
	}
	else
	{

		char *left=(char*)malloc(sizeof(char)*1001);
		char *right=(char*)malloc(sizeof(char)*1001);
		char *multi=(char*)malloc(sizeof(char)*1001);
		char *differ=(char*)malloc(sizeof(char)*1001);
		strcpy(left,"1");
		strcpy(right,intal1);
		char *mid=(char*)malloc(sizeof(char)*1001);
		while(intal_compare(left,right)!=1)
		{	
			free(mid);
			mid=divide_by_two(intal_add(left,right));
			
			free(multi);
			multi=intal_multiply(mid,intal2);
			
			if(intal_compare(multi,intal1)==1)
			{
				free(right);
				right=intal_diff(mid,"1");
			
			}
			else
			{
				free(differ);
				differ=intal_diff(multi,intal1);
			
				if(intal_compare(differ,intal2)!=1)
					return differ;
				else
				{
					free(left);
					left=intal_add(mid,"1");
			
				}
			}

		}
		return differ;
	}
}

char* intal_pow(const char* intal1, unsigned int n)
{
	char *b=(char*)malloc(sizeof(char)*2);
	char *result=(char*)malloc(sizeof(char)*1002);
	char *pre=NULL;
	if(n==0)
	{
		b[0]='1';
		b[1]='\0';
		return b;
	}
	if(strcmp(intal1,"0")==0)
	{
		b[0]='0';
		b[1]='\0';
		return b;
	}
	else
	{
		strcpy(result,"1");
		result[1]='\0';
		for(int i=0;i < n;i++)
		{		pre=result;
				result=intal_multiply(result,intal1);
				free(pre);
		}
		return result;
	}
}
char* intal_gcd(const char* intal1, const char* intal2)
{


	if(strcmp(intal2,"0")==0 || strcmp(intal1,"0")==0)
	{	char *b=(char*)malloc(sizeof(char)*2);
		b[0]='0';
		b[1]='\0';	
		return b;
	}
	else
	{
		char *result1=(char*)malloc(sizeof(char)*1001);
		char *result2=(char*)malloc(sizeof(char)*1001);
		char *pre=NULL;
		if(intal_compare(result1,result2) ==1)
		{	strcpy(result2,intal1);
			strcpy(result1,intal2);
			while(strcmp(result2,"0")!=0)
			{	
				pre=result2;
				result2=intal_mod(result1,result2);
				free(result1);
				result1=pre;
				//printf("sd" );
			}
			return result1;
		}
		else
		{
			strcpy(result1,intal1);
			strcpy(result2,intal2);
			while(strcmp(result2,"0")!=0)
			{	
			
				pre=result2;
				result2=intal_mod(result1,result2);
				free(result1);
				result1=pre;

			}
			return result1;
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
		if(n==0){
			free(arr2);
			free(arr3);
			arr1[1]='\0';
			return arr1;
		}
		else{
			free(arr1);
			free(arr3);
			arr1[2]='\0';
			return arr2;
		}
	}
	n-=2;
	for(unsigned int i=0;i <= n;i++){		
		arr3=intal_add(arr1,arr2);
		free(arr1);
		arr1=arr2;

		arr2=arr3;
	}
	return arr3;

}


char* intal_factorial(unsigned int n)
{
	char *result=(char*)malloc(sizeof(char)*1001);
	strcpy(result,"1");
	if(n==0)
	{	result[1]='\0';
		return result;
	}
	char * temp=(char*)malloc(sizeof(char)*1001);
	for(unsigned int i=1;i <=n ;i++)
	{
		sprintf(temp, "%d", i);
		//printf("%s %s \n",temp,result );
		result=intal_multiply(result,temp);

	}
	//printf("%s\n",result );
	return result;
}
 
char* intal_bincoeff(unsigned int n, unsigned int k)  
{ 

    char **temp=malloc(sizeof(char*)*k+1);
    for(int i=0;i<k+1;i++)
    {
    	temp[i]=(char *)calloc(sizeof(char),1001);
    	temp[i][0]='0';
    	temp[i][1]='\0';
    } 
  
    temp[0][0] = '1';  
  	temp[0][1]='\0';

  	int mid;

  	if(n%2)
  		mid=n/2+1;
  	else
  		mid=n/2;
    for (int i = 1; i <= mid; i++) 
    { 

        int mi=i;
	  	if(k<i)
  			mi=k;
        for (int j = mi; j > 0; j--) 
            temp[j] =intal_add(temp[j] ,temp[j-1]); 
    } 
    mid++;
    for (int i = mid; i <= n; i++) 
    { 

        int mi=i;
	  	if(k<i)
  			mi=k;
        for (int j = mi; j >i-mid ; j--) 
            temp[j] =intal_add(temp[j] ,temp[j-1]); 
    } 
    return temp[k]; 
} 

int intal_max(char **arr, int n)
{
	int temp;
	char *result=arr[0];
	for(int i=1;i < n;i++)
	{
		if(intal_compare(arr[i],result)==1)
		{
			result=arr[i];
			temp=i;
		}
	}
	return temp;
}
int intal_min(char **arr, int n)
{
	int temp;
	char *result=arr[0];
	for(int i=0;i < n;i++)
	{
		if(intal_compare(arr[i],result)==-1)
		{
			result=arr[i];
			temp=i;
		}
	}
	return temp;
}

int intal_search(char **arr, int n, const char* key)
{

	char *result=malloc(sizeof(char)*1001);
	strcpy(result,key);
	for(int i=0;i < n;i++)
	{
		if(intal_compare(arr[i],result)==0)
		{
			return i;
		}
	}
	return -1;
}
static void merge(char **arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    char **L=malloc(sizeof(char *)*n1);
    char **R=malloc(sizeof(char *)*n2); 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (intal_compare(L[i], R[j])!=1) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    free(L);
    free(R);
} 
  

static void mergeSort(char **arr, int l, int r) 
{ 
    if (l < r) 
    { 

        int m = l+(r-l)/2; 

        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}
void intal_sort(char **arr, int n)
{
	mergeSort(arr, 0, n-1); 
}

int intal_binsearch(char **arr, int n, const char* key)
{	int l=0;
	int r=n-1;

    while (l <= r) { 
        int m = l + (r - l) / 2; 
  		int z=intal_compare(arr[m],key);	
  

  
        if (z==-1) 
            l = m + 1; 
  
  
        else
            r = m - 1; 
    } 
  if(intal_compare(arr[l],key)==0)
  	return l;
  
    return -1; 
}

char* coin_row_problem(char **arr, int n)
{
	char *a=malloc(sizeof(char)*2);
	char *result=malloc(sizeof(char)*1001);
	char *b=malloc(sizeof(char)*1001);
	a[0]='0';
	a[1]='\0';

	strcpy(b,arr[0]);
	char *temp=NULL;

	for(int i=1;i<n;i++)
	{
		if(i%2)
		{
			temp=intal_add(a,arr[i]);
			if(intal_compare(temp,b)==1)
			{
				char *g=a;
				a=temp;
				free(g);

			}
			else{
				strcpy(a,b);
				free(temp);
			}
		}
		else{
			temp=intal_add(b,arr[i]);
			if(intal_compare(temp,a)==1)
			{
				char *g=b;
				b=temp;
				free(g);

			}
			else{
				
				strcpy(b,a);
				free(temp);
			}

		}
	}
	if(intal_compare(a,b)==1){
		strcpy(result,a);
		
	}
	else{
		strcpy(result,b);

	}
	free(a);
	free(b);
	return result;
}

