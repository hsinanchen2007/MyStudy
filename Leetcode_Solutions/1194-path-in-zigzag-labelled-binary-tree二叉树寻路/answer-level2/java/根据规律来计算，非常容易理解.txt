规律：
1. 每一层的最大值和最小值是固定的
2. 由于正顺和逆序，造成每个数字与上一节点数字的对应关系发生偏移。即得知正序的位置后，反转即可得逆序的数字

综上。首先计算出label所在的层级数，然后顺序逆推回去
```
public List<Integer> pathInZigZagTree(int label) {
        int min = 1, max = 1, layer = 0;
        while (label > max) {
            min *= 2;
            max = max * 2 + 1;
            layer++;
        }
        List<Integer> result = new ArrayList<>();
        result.add(label);
        while (layer > 0) {
            label /= 2;
            min /= 2;
            max /= 2;
            layer--;
            label = max - min + max - label + 1;
            result.add(0, label);
        }
        return result;
    }
```
