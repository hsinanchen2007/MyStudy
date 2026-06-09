### 解题思路
java用hashmap求解 在比赛的时候的想法是先将arr深拷贝到数组a，然后将a排序，接着遍历arr，找到arr[i]在排

序数组a中的位置，其大小为下标加一，但是这种方法时间复杂度为n方，所以会超出时间限制。

因此通过hashmap提高存取速度，key为数组元素，value为元素对应的rank

### 代码

```java
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
class Solution {
    public static int[] arrayRankTransform(int[] arr) {
        int a[]=new int[arr.length];
        a=arr.clone();
        Arrays.sort(a);
        Map<Integer,Integer> map=new HashMap<>();
        int index=1;
        for(int i=0;i<a.length;i++) {
        	if(i>0&&a[i]!=a[i-1]) {
        		map.put(a[i], index);
        		index++;
        	}
        	if(i==0) {
        		map.put(a[i], index);
        		index++;
        	}
        }
        for(int i=0;i<arr.length;i++) {
        	arr[i]=map.get(arr[i]);
        }
        return arr;
    }
}
```