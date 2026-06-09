**方法一：双指针滑动**
```
class Solution {
    /**
    * 思路：
    * 定义两个指针选择和为target的正整数区间
    * (1) 定义两个指针从正整数1开始，定义一个list以方便添加所有符合条件的区间数组。
    * (2) 由题至少含有两个数，所以左指针一定小于等于 target/2 ，target为奇数的时候可等于。
    * (3) 在条件(i <= target)下，从左右指针为 1 开始循环
    *       如果区间数字和小于target，则之前和加上右指针，然后右指针加一；
    *       如果区间数字和大于target，则之前和减去左指针，然后左指针加一；
    *       如果区间数字和等于target，则记录当前数组，然后之前和减去左指针，左指针加一继续遍历；
    *       直到 i > target 跳出循环。
    */
    public int[][] findContinuousSequence(int target) {
        // 左指针
        int i = 1;
        // 右指针
        int j = 1;
        // 区间中数字的和(左闭右开)
        int sum = 0;
        List<int[]> res = new ArrayList<>();
        while (i <= target / 2) {
            if (sum < target) {
                // 右指针向右移动
                sum += j++;
            } else if (sum > target) {
                // 左指针向右移动
                sum -= i++;
            } else {
                // 记录结果
                int[] arr = new int[j-i];
                for (int k = i; k < j; k++) {
                    arr[k-i] = k;
                }
                res.add(arr);
                // 左指针向右移动
                sum -= i++;
            }
        }
        return res.toArray(new int[res.size()][]);
    }
}
```

**方法二：数学思路**
```
class Solution {
    /**
    * 思路：
    * 由题和为target的连续正整数序列，根据target和序列长度可以很容易算出每一位数字。
    * (1) 假设数列长度为i，第一位数字为n，则target=n+(n+1)+...+(n+i-1)=k*n+(1+2+...+(i-1))
    * (2) 根据(1)从长度为2开始依次算出符合条件的数组。
    */
    public int[][] findContinuousSequence(int target) {
        List<int[]> list = new ArrayList<>();
        int i = 1;
        while(target>0){
            target -= i++;
            if(target>0 && target%i == 0){
                int[] array = new int[i];
                for(int k = target/i, j = 0; k < target/i+i; k++,j++){
                    array[j] = k;
                }
                list.add(array);
            }
        }
        Collections.reverse(list);
        // 调用含参toArray方法，传入要转换部分的泛型。
        return list.toArray(new int[0][]);       
    }
}
```
