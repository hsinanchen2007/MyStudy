### 解题思路
1.从个位数开始往高位数遍历，如果每个高位数都大于相邻的低位数，则此数字已经是最大的了，直接返回-1。
2.否则遍历直到发现首次出现高位数比相邻的低位数小的情况（称这个高位数所在的位为“分界点”），这时应该在分界点右边的所有数里面找出最小的比它大的数，把两个数交换位置，此时“分界点”右边的数仍然是从大到小，两两交换使它们顺序改为从小到大，然后转换成int返回。

### 代码

```java
class Solution {
    public int nextGreaterElement(int n) {
        char[] chars = String.valueOf(n).toCharArray();
        for(int i = chars.length - 1; i > 0; --i){
            if(chars[i - 1] >= chars[i]) continue;
            --i;
            int j = i;
            while(j != chars.length - 1 && chars[j + 1] > chars[i]) ++j;
            swap(chars, i , j);
            for(int k = i + 1; k <= i + (chars.length - 1 - i) / 2; ++k){
                swap(chars, k, chars.length + i - k);
            }
            try{
                return Integer.parseInt(new String(chars));
            }
            catch (Exception e){
                return -1;
            }
        }
        return -1;
    }
    
    private void swap(char[] chars, int i, int j){
        char t = chars[i];
        chars[i] = chars[j];
        chars[j] = t;
    }
}
```