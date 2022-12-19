
```
class Solution {
    public int[] sortByBits(int[] arr) {
		 
		 for(int i=0;i<arr.length;i++) {
			 for(int j=i+1;j<arr.length;j++) {
				 String a = Integer.toBinaryString(arr[i]);
				 String b = Integer.toBinaryString(arr[j]);
				 if(getCount(a,"1")>getCount(b, "1")) {
					 arr[i]=arr[i]^arr[j];
					 arr[j]=arr[j]^arr[i];
					 arr[i]=arr[i]^arr[j];
				 }
				 if(getCount(a,"1")==getCount(b, "1")) {
                     if(arr[i]>arr[j]){
                    arr[i]=arr[i]^arr[j];
					 arr[j]=arr[j]^arr[i];
					 arr[i]=arr[i]^arr[j];
                     }
					 
				 }
			 }
		 }
		return arr;
		 
	 }
	 
	 public int getCount(String str,String key) {
		 int i=str.length()-str.replace(key, "").length();
		 return i/key.length();
	 }
}
```
