### 解法1
将每一行的d[i]加上上一行的d[i-1][j-1]和d[i-1][j]的最小值，得到最后一行的最小值就是最短路径
![120_A.gif](https://pic.leetcode-cn.com/aaecdb935e728b852d921fe2ec7d64d76c666abd03c2a3db8a0bccdf7a99aa39-120_A.gif)

```
    public int minimumTotal(List<List<Integer>> triangle) {
        //子上而下计算每个位置的最小值 最终 最后一行的最小值则是 最短路径
        for (int i = 1; i < triangle.size(); i++) {
            List<Integer> sub0 = triangle.get(i-1);
            List<Integer> sub = triangle.get(i);
            for (int j = 0; j < sub.size(); j++) {
                if (j == 0){
                    sub.set(j,sub.get(j)+sub0.get(j));
                }else if (j == sub.size()-1){
                    sub.set(j,sub.get(j)+sub0.get(j-1));
                }else {
                    Integer min = Math.min(sub0.get(j),sub0.get(j-1));
                    sub.set(j,min+sub.get(j));
                }
            }
            triangle.set(i,sub);
        }
        List<Integer> sub = triangle.get(triangle.size()-1);
        int min = Integer.MAX_VALUE;
        for (int i = 0; i <sub.size() ; i++) {
            min = Math.min(sub.get(i),min);
        }
        return min;
    }

```
### 解法2
子下而上计算每个位置的最小值 最终 第一行的值则是 最短路径
![120_3.png](https://pic.leetcode-cn.com/14bff96390993465d69b86dac5f2caed3b0073fa9867c8f09ee68d28bc562b22-120_3.png)

```
    public int minimumTotal2(List<List<Integer>> triangle) {
        //子下而上计算每个位置的最小值 最终 第一行的值则是 最短路径
        if (triangle.size() == 0)return 0;
        for (int i = triangle.size()-2; i >-1; i--) {
            List<Integer> sub0 = triangle.get(i);
            List<Integer> sub = triangle.get(i+1);
            for (int j = 0; j < sub.size()-1; j++) {
                Integer min = Math.min(sub.get(j),sub.get(j+1));
                sub0.set(j,min+sub0.get(j));
            }
        }
        return triangle.get(0).get(0);
    }
```

[感受迭代的艺术吧 欢迎交流 欢迎start 持续分享好玩的题目和解法](https://github.com/ifgyong/leetCode/wiki)

[感受迭代的艺术吧 欢迎交流 欢迎start 持续分享好玩的题目和解法](https://github.com/ifgyong/leetCode/wiki)

[感受迭代的艺术吧 欢迎交流 欢迎start 持续分享好玩的题目和解法](https://github.com/ifgyong/leetCode/wiki)