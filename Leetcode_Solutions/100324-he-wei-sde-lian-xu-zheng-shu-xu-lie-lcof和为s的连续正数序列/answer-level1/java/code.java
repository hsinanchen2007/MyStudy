### 解题思路
都在注释里了。。。

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        //1,2不在考虑范围内
        if(target <= 2){
            return new int[][]{};
        }else{
            List<int[]> list = new LinkedList<int[]>();
            //因为要求从小到大输出，因此从中间往回遍历
            int i = target / 2;
            do{
                //取得中间值
                int avg = target / i;
                //判断当前的个数是不是偶数个
                boolean isEven = i % 2 == 0;
                if(isEven){
                    //偶数
                    //取得的模必须等于个数的一半且平均值
                    //防止取到负数，平均值必须大于等于个数的一半
                    if(target % i == i / 2 && avg >= i / 2){
                        add(list, i, avg);
                    }
                }else{
                    //奇数
                    //必须整除
                    //防止取到负数，平均值必须大于个数的一半
                    if(target % i == 0 && avg > i / 2){
                       add(list, i, avg);
                    }
                }
                i--;
                //不能是自己本身，因此排除个数为1
            }while(i > 1);
            //返回二维数组
            return list.toArray(new int[list.size()][]);
        }
    }

    public void add( List<int[]> list, int i, int avg){
        int[] arr = new int[i];
        //数组要求从小到大，然后从最后往前加（个人喜好加法）
        for(int j = i / 2, k = i; k > 0; k--, j--){
            arr[k - 1] = avg + j;
        }
        list.add(arr);
    }
}
```