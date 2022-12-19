```
 bool checkIfExist(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    int n=arr.size();
	int cl=0;
    for(int i=0;i<n-1;i++){
		if(arr[i]==0)cl++;
		if(arr[i]>0){
		   for(int j=i+1;j<n;j++){
			  if(arr[j]==2*arr[i])return true;
			  if(arr[j]>2*arr[i])break;
		   }
		}else if(arr[i]<0&&i>0){
			for(int k=i-1;k>=0;k--){
				if(arr[k]==2*arr[i])return true;
				if(arr[k]<2*arr[i])break;
			}
		}
	}
    if(arr[n-1]==0)cl++;
    if(cl>=2)return true;	
	return false;
}
```
