```
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        // 保存当前深度，然后根据深度的奇偶来对半分配
        int currentDepth = 0;
        int result[] = new int[seq.length()];
        for(int i = 0; i < seq.length(); i++){
            // 如果当前入 “栈” 的是 ‘(’ ，那么深度就会增加，反之减少
            if(seq.charAt(i) == '('){
                result[i] = currentDepth % 2;
                currentDepth ++;
            }else{
                currentDepth --;
                result[i] = currentDepth % 2;
            }
        }
        return result;
    }
}
```

，，，有种感觉这题是阅读理解把难度提高到了中等 /_ \