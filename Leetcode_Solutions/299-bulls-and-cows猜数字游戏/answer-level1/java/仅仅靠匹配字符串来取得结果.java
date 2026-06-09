由于作为 答案的字符串secret 和作为 猜测的字符串guess 仅有数字，因此可以创建两个 仅需10位的int型数组 来储存各数字的数量。
遍历两个字符串，将数组每个位子上的数量相加，得到 count。
再遍历一次获得位置正确、数字正确的数字数量，得到 correct。
则：correct 为“公牛”数量，count - correct 为“母牛”数量。

```
class Solution {
    public String getHint(String secret, String guess) {
        int[] nums1 = new int[10];
        int[] nums2 = new int[10];
        int count = 0,correct = 0;
        for(int i = 0;i < secret.length();i++){
            nums1[(int)secret.charAt(i) - '0']++;
        }
        for(int i = 0;i < guess.length();i++){
            nums2[(int)guess.charAt(i) - '0']++;
        }
        for(int i = 0;i < nums1.length;i++){
            count += Math.min(nums1[i],nums2[i]);
        }
        for(int i = 0;i < secret.length();i++){
            if(secret.charAt(i) == guess.charAt(i)){
                correct++;
            }
        }
        return correct + "A" + (count - correct) + "B";
    }
}
```
