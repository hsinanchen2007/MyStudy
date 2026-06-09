#### 方法一：暴力法
- 基本思路：根据题意可以知道，我们需要为一个函数提供 **两个参数**，当参数等于某个 **给定的值** 时，将参数记录下来，所以可以利用 **二重循环**，遍历两个参数的所有取值，当函数结果等于给定的值时，就将参数记录下来。
- 优化：由题意可知，函数是 **单调递增** 的，所以当函数结果 **大于等于** 给定的值时，就可以 **结束** 当前循环，因为根据函数单调的性质，后面的值必然也是大于给定的值的。
- 时间复杂度：$O($n^{2}$)$
#### 代码：
```java [-Java]
class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 1; i <= 1000; i++) {
            if (customfunction.f(i,1) > z) {
                break;
            }
            for (int j = 1; j <= 1000; j++) {
                if (customfunction.f(i,j) == z) {
                    List<Integer> list = new ArrayList<>();
                    list.add(i);
                    list.add(j);
                    res.add(list);
                    break;
                } else if(customfunction.f(i,j) > z){
                    break;
                }
            }
        }
        return res;
    }
}
```
##### 方法二：二分查找
- 基于暴力法的优化，将内层循环变为二分查找。
- 时间复杂度：$O($nlog_{2}n$)$
#### 代码：
```java [-Java]

class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 1; i <= 1000; i++) {
            if (customfunction.f(i,1) > z) {
                break;
            }
            int left = 1;
            int right = 1000;
            while (left <= right) {
                int mid = (right + left) / 2;
                int temp = customfunction.f(i,mid);
                if (temp == z) {
                    List<Integer> list = new ArrayList<>();
                    list.add(i);
                    list.add(mid);
                    res.add(list);
                    break;
                } else if (temp > z) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return res;
    }
}
```

##### 方法三：双指针法
- 既然函数是单调有序的，那么自然可以使用双指针法来代替二重循环。
- 时间复杂度：$O($n$)$
#### 代码：
```java [-Java]
class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> res = new ArrayList<>();
        int left = 1;
        int right = 1000;
        while (left <= 1000 && right >= 1) {
            int temp = customfunction.f(left,right);
            if (temp == z) {
                List<Integer> list = new ArrayList<>();
                list.add(left);
                list.add(right);
                res.add(list);
                left++;
            } else if (temp > z) {
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
}
```