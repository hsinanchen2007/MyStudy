从右往左遍历确实是个非常好的思路，这样只需 O(n) 的时间复杂度和 O(1) 的空间复杂度即可得到结果，Java 代码：
```
public int[] replaceElements(int[] arr) {
        //待遍历元素的右侧(值)最大元素，初始值为 -1
        int rightMax = -1;
        //从最后一个元素(右)开始往前(左)遍历
        for (int i = arr.length - 1; i >= 0; i--){
            //先缓存当前元素的值
            int temp = arr[i];
            //当前元素的值重新赋为其右侧最大元素的值
            arr[i] = rightMax;
            //计算下一个待遍历元素的右侧元素的最大值
            rightMax = Math.max(temp, rightMax);
        }
        return arr;
    }
```
