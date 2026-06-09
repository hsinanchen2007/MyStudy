### 解题思路
此处撰写解题思路
刚刚学会快排，就遇到此题，但是这个要返回动态数组，就需要稍稍改变一点，让动态赋值于一个数组，方便后面的操作

### 代码

```cpp
class Solution { 

void quicksort(int A[],int p,int r){
	
	int q;
	if(p<r){
		int i=p-1,j,x=A[r];
		for(j=p;j<r;j++){
			if(A[j]<=x){
				i++;
				swap(A[i],A[j]);
			} 
		}
		
		swap(A[i+1],A[r]);
		q=i+1;
	
	quicksort(A,p,q-1);
	quicksort(A,q+1,r);
		
	}
	
}

public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        int i;
        int A[10000000];
        for(i=0;i<arr.size();i++){
            A[i]=arr[i];
        }

        quicksort(A,0,i-1);

        for (int i = 0; i < k; ++i)
         {
             vec[i]=A[i];
         }
        return vec;
    }


   






};
```