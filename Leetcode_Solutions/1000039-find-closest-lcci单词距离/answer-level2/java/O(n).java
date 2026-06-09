### 解题思路
通过两个数组，保存该位置到前一个word1的距离和到后一个word1的距离；
然后遍历words，如果是word2，则数组下标和两个距离数组做差值，更新最小值。

### 代码

```java
class Solution {
    public int findClosest(String[] words, String word1, String word2) {
        int []exist_pre = new int[words.length];
        int []exist_last = new int[words.length];
        Arrays.fill(exist_pre,-1);
        for(int i = 0;i < words.length;i++) if(word1.equals(words[i])) exist_pre[i] = i;
        int last = -1;
        for(int i = words.length -1;i >=0;i--){
            if(exist_pre[i]!=-1){ last = exist_pre[i];}
            exist_last[i] = last;
        }
        int pre = -1;
        for(int i = 0;i < words.length;i++){
            if(exist_pre[i]!=-1){ pre = exist_pre[i];}
            exist_pre[i] = pre;
        }
        int res = Integer.MAX_VALUE;
        for(int i = 0;i < words.length;i++){
            if(word2.equals(words[i])){
                if(exist_pre[i] != -1) res = Math.min(res,i - exist_pre[i]);
                if(exist_last[i] != -1) res = Math.min(res,exist_last[i] - i);
            }
        }
        return res;
    }
}
```