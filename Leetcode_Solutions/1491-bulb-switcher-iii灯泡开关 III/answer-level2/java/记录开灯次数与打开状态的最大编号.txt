### 两种解法

##### 1.暴力法（我的解法）

```java
	public int numTimesAllBlue(int[] light) {
        int n = light.length;
        boolean[] on = new boolean[n];
        int count = 0;
        int last = 0;
        for(int i = 0; i < n; i++){
            count++;
            on[light[i] - 1] = true;
            last = Math.max(last, light[i] - 1);
            for(int j = 0; j < last; j++){
                if(!on[j]){
                    count--;
                    break;
                }
            }
        }
        return count;
    }
```

思路分析：

* 从0开始的每一个时刻，都将`light[k]`这个灯打开，每一个时刻都要判断当时所有打开的灯左边的灯是否全处于打开状态。所以我们需要用一个布尔数组`boolean[] on`表示灯的开/关状态：`on[i]`为真表示`i`编号的灯已经打开。
* 只要编号最大的灯左边的所有灯都打开了，就可以保证所有打开的灯左边的灯全是打开状态。
* 用暴力法解决，每一时刻开灯后，都先确定现在已开的的灯中的最大编号`last = Math.max(last, light[i] - 1);`。然后查看其左边是否已经所有灯都打开了，如果是则满足题意的时刻的数量加1。
* 时间复杂度为$O(n^2)$，空间复杂度为$O(n)$。

代码解释：

* 在对于每个时刻的循环中，第7行，我们都首先默认该时刻是满足条件的，然后在10-15行对最大编号灯泡的左边进行遍历检查时，一旦发现不符合条件，就将该时刻去除（12行）。

##### 2.线性解法

```java
	public int numTimesAllBlue2(int[] light) {
        int res = 0;
        int maxNum = 0; // 记录点亮过的灯泡的最大编号
        for(int i = 0; i < light.length; i++){
            maxNum = Math.max(maxNum, light[i]);
            if(i + 1 == maxNum)
                res++;
        }
        return res;
    }
```

思路分析：

* 从0开始的每一个时刻，都将`light[k]`这个灯打开，每一个时刻都要判断当时所有打开的灯左边的灯是否全处于打开状态。
* 换一个检查上述条件的方式，如果打开的灯中，最大的编号为`maxNum`，那么其左边的灯都打开的话，加上它本身肯定已经打开了`maxNum`次灯泡。注意我们是从第0时刻打开第一颗灯泡的。
* 所以第`i`时刻满足`i + 1 == maxNum`，说明该时刻满足所有打开的灯左边的灯都打开了。反之，如果`i + 1 ！= maxNum`，打开灯的数量少于开着的灯中编号最大值，其中肯定还有灯泡没有被打开。
* 时间复杂度为$O(n)$，空间复杂度为$O(1)$。