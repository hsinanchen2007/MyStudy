### 解题思路
用官方（C++）改写成JAVA代码会出问题，修正点如下：
先 (n1 - 1 - k) / (i - k) 得到int整数之后，再乘以一个重复模板中s2的数量(countr[i] - countr[k]) ，得到所有的重复模板中s2的数量。


### 代码

```java
class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {

        if(s1.length() ==0 || s2.length()==0 || n1==0 || n2 ==0) return 0;

        char[] s1Chars = s1.toCharArray();
        char[] s2Chars = s2.toCharArray();

        int count = 0;
        int index = 0;
        int[] indexr = new int[s2Chars.length+1];
        int[] countr = new int[s2Chars.length+1];
        for(int i=0;i<n1;i++){
            for(int j = 0; j<s1Chars.length;j++){
                if(s1Chars[j] == s2Chars[index]) {
                    if(index == s2Chars.length -1) {
                        count++;
                        index = 0;
                    }else{
                        index++;
                    }
                    
                }
                
            }
            countr[i] = count;
            indexr[i] = index;
            for (int k = 0; k < i; k++) {
                if (indexr[k] == index) {
                    int prev_count = countr[k];
                    int pattern_count = ((n1 - 1 - k) / (i - k))*(countr[i] - countr[k]);
                    int remain_count = countr[k + (n1 - 1 - k) % (i - k)] - countr[k];
                    return (prev_count + pattern_count + remain_count) / n2;
                }
            }
        }

        return countr[n1 - 1] / n2;
    }
}
```