### 解题思路
用数组存字符对应的数字，然后遍历数组相加，如果是最后一位，直接加上然后退出，请大佬指正

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        int result=0;
        int [] arr= new int[s.length()];
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='I'){
                arr[i]=1;}
            if(s.charAt(i)=='V'){
                arr[i]=5;}
            if(s.charAt(i)=='X'){
                arr[i]=10;}
            if(s.charAt(i)=='L'){
                arr[i]=50;}
            if(s.charAt(i)=='C'){
                arr[i]=100;}
            if(s.charAt(i)=='D'){
                arr[i]=500;}
            if(s.charAt(i)=='M'){
                arr[i]=1000;}
        }
        for(int i=0;i<s.length();i++){
            if(i==s.length()-1){
            result=result+arr[s.length()-1];
            break;
            }
            if(arr[i]<arr[i+1]){
                result=result+arr[i+1]-arr[i];
                i++;
            }else{
                result=result+arr[i];
            }
        }
        
        return result;

    }
}
```