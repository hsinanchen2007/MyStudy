```java
class Solution {
    public String reverseStr(String s, int k) {
        char[] charArr = s.toCharArray();
        int step = 2*k;//步長
        int len = s.length();
        for (int i = 0; i < len; i=i+step) {
            int end = Math.min(len-1, i + k - 1);//重点
            reverSubString(charArr, i, end);
        }
        return String.valueOf(charArr);
    }

    public static void reverSubString(char[] nums,int start,int end){
        while(start<end){
        	char tmp = nums[start];
        	nums[start] = nums[end];
        	nums[end] = tmp;
        	start++;
        	end--;
        }
    }
}
```