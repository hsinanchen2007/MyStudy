执行用时 :7 ms, 中击败了48.28%的用户。
内存消耗 :38.1 MB,击败了79.25%的用户。
```
class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        int count = 0;
        Arrays.sort(tokens);
        int left = 0;
        int right = tokens.length-1;
        //token排序后，能量足够的情况下优先使用令牌值较小的得分，否则优先使用令牌值较大的获取能量
        //直到令牌用完或使用分数获取的能量不足以使用下一个令牌得分
        while (left <= right){
            if(tokens[left] <= P){
                count++;
                P -= tokens[left];
                left++;
                continue;
            }
            if(count > 0){
                if(tokens[right] > tokens[left]){
                    P+= tokens[right] - tokens[left];
                    right--;
                    left++;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
        return count;
    }
}
```