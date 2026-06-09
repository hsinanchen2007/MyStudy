定义一个长度128，值为0的数组，每个字符出现一次在对应的位置+1；最后根据字符出现的奇偶次统计


```
class Solution {
    public int longestPalindrome(String s) {
        int[] temp = new int[128];
        int oddNum = 0;     //出现奇数次的元素个数
        int evenNum = 0;    //出现偶数次的元素个数
        for(int i=0;i<s.length();i++){
            temp[s.charAt(i)]++;
        }
        for(int i = 0;i<temp.length;i++){
            if(temp[i] == 0){
                continue;
            }
            evenNum = evenNum + temp[i]/2;
            if((temp[i] & 1) != 0){    //相当于除2取余
                oddNum++;
            }
        }
        if(oddNum == 0){
            return evenNum*2;
        }else{
            return evenNum*2+1;
        }
    }
}
```
