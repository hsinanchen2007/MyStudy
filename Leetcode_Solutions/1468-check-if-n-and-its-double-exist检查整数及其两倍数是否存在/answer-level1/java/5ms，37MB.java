记录一下第一个双百。
![截屏2020-02-09下午7.09.55.png](https://pic.leetcode-cn.com/d33ad7da0a3eba59a78b5699b8ea7269e418872f555ee0ac4da340b2d7172d6f-%E6%88%AA%E5%B1%8F2020-02-09%E4%B8%8B%E5%8D%887.09.55.png)

### 代码

```java
class Solution {
    public boolean checkIfExist(int[] arr) {
        Arrays.sort(arr);
        int i = 0, n = arr.length;
        for(; i<n-1 ;i++) {
            for(int j = n-1; j>i; j--) {
                if(arr[i] * 2==arr[j] || arr[j] * 2==arr[i])
                    return true;
                else if(arr[i] * 2 > arr[j])
                    break;
            }
        }
        return false;
    }
}
```