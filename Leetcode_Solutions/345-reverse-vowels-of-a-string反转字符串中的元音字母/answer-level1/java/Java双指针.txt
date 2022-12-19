使用双指针，找到元音字母，然后交换；  
执行用时 :2 ms, 在所有 Java 提交中击败了100.00%的用户    
内存消耗 :36.3 MB, 在所有 Java 提交中击败了99.10%的用户    
```java
class Solution {
    public String reverseVowels(String s) {
        char[] arr = s.toCharArray();
        int l=0, r=arr.length-1;
        while(l<r){
            while(l<arr.length && judge(arr[l])) l++;
            while(r>=0 && judge(arr[r])) r--;
            if(l>=r){
                break;
            }
            char tmp = arr[r];
            arr[r--] = arr[l];
            arr[l++] = tmp;
        }
        // String result = String.valueOf(arr);
        String result = new String(arr);
        return result;
    }
    public boolean judge(char c){
        if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u' && c!='A' && c!='E' && c!='I' && c!='O' && c!='U'){
            return true;
        }else{return false;}
    }
}
```