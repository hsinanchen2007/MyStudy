### 解题思路

- 空间换时间
- 1.按照value非升序将values和labels捆绑排序
- 2.从value大的开始贪心，判断当前的labels有没有超过use_limit
- 3.每找到一个，num_wanted自减1

### 代码

```java
class Solution {

    class Data {
        Integer value;
        Integer label;
        Data(int value, int label) {
            this.value = value;
            this.label = label;
        }
    }

    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        // labels[i]<=20000，摆明了让空间换时间的
        int len = values.length;
        Data[] data = new Data[len];
        for (int i = 0; i < len; ++i) {
            data[i] = new Data(values[i], labels[i]);
        }

        // 按照value排序,降序
        Arrays.sort(data, (Data d1, Data d2) -> Integer.compare(d2.value, d1.value));

        int ans = 0;
        int[] count = new int[20001];
        for (int i = 0; i < len; ++i) {
            if (0 == num_wanted) {
                break;
            }
            if (count[data[i].label] < use_limit) {
                ans += data[i].value;
                ++count[data[i].label];
                --num_wanted;
            }
        }
        return ans;
    }
}
```