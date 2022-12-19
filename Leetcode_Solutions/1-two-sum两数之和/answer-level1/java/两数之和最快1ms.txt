# 方法一，使用Hash表 + 位置列表处理

```
// MAP 存储数字到位置映射
Map<Integer, List<Integer>> n2p = new HashMap<>();
int len = nums.length;
int diff = 0;
for (int i = 0; i < len; i++) {
    // 判断当前数字是否有对应位置，防止重复用的列表 number 2 position
    if (!n2p.containsKey(nums[i])) {
        n2p.put(nums[i], new ArrayList<Integer>());
    }
    n2p.get(nums[i]).add(i);

    diff = target - nums[i];

    if (n2p.containsKey(diff)) {
        if (diff == nums[i]) {
            if (n2p.get(diff).size() > 1) {
                return new int[] { n2p.get(diff).get(0), n2p.get(diff).get(1) };
            } else {
                continue;
            }
        } else {
            return new int[] { n2p.get(diff).get(0), n2p.get(nums[i]).get(0) };
        }
    }
}
```

上述代码就用到了一个Hash表，不过为了防止输入中存在重复值，例如[3,3]，和为6的情况，使用了列表的方式。很像Redis中Key Value实现。在其他的解题中，很多使用了一个Hash Map的解法，压根没有考虑这种情况从而造成了错误。

以上解法的缺点，是针对位置列表操作有点繁琐。代码不整洁。

# 方法二，使用Hash表的简洁解法

方法二来自别人的提交，这里略作修改，这里全列出来，当做分析。

```
int[] result = new int[2];
Map<Integer, Integer> map = new HashMap<>(nums.length);
for (int i = 0; i < nums.length; i++) {
    int value = target - nums[i];
    Integer index = map.get(value);
    if (index != null && index != i) {
        return new int[]{i, index};
    }
    map.put(nums[i], i);
}
return null;
```

非常简洁的解法，完全考虑了重复情况下的HashMap处理。不过这里有个预设的前提———只找出一对就行。所以针对这个做了简化，很取巧，但是非常好用，代码清晰明了。
精髓就在那个if 判断上。还是以[3,3]为例，第二个3处理中的时候，按照预设会找到第一个3的位置，发现跟当前的位置不一样，才进行处理，否则不处理。

# 方法三，位运算+补码处理

一样来自他人的提交，略作修改便于阅读。这里主要利用了Java的补码机制。预算速度仅1ms。

```
int indexArrayMax = 2047;
int[] indexArrays = new int[indexArrayMax + 1];
int diff = 0;
for (int i = 0; i < nums.length; i++) {
    diff = target - nums[i];
    if (indexArrays[diff & indexArrayMax] != 0) {
        return new int[] { indexArrays[diff & indexArrayMax] - 1, i };
    }
    indexArrays[nums[i] & indexArrayMax] = i + 1;
}
throw new IllegalArgumentException("No two sum value");
```

主体思想还是一样是找当前的差的位置有没有在以前处理过，如果处理过，则返回相应的值。这里巧妙的用了数组，前提是——样本提供的数量有限，不然indexArrayMax还得扩大。

先说说为啥有个indexArrayMax = 2047，在java中，2047是正整数，对应原码和补码一样，都是11111111111。

然后开了个大小为2048的数组，int[] indexArrays = new int[indexArrayMax + 1]，为了是考虑有0的情况。这个也是预设了样本空间的大小，如果不够，只要再找一个原码全是1，大小比2047大的就行了。方法很简单，原码多加一个1，就行了。可以用
```
System.out.println(Integer.toBinaryString(2047));
System.out.println(0b11111111);
```
来找你合适的大小数字。

diff，存储差的变量。 

然后开始循环数组计算差。注意，差有可能是负数！

之后这里是关键
```
if (indexArrays[diff & indexArrayMax] != 0) {
    return new int[] { indexArrays[diff & indexArrayMax] - 1, i };
}
```
indexArrays 这个数组默认初始化都是0，所以用diff & indexArrayMax去做下标处理。diff & indexArrayMax的结果有三种

- 如果，差是正数，那么结果=差
- 如果，差是0，那么结果还是0（因为用的是补码，不像反码那样区分正负0）
- 如果，差是负数，那么结果是会被转化为0-2047之间的正数，存放到相应的位置，负值越大，越接近2047，反之越接近0。look这里
```
System.out.println(Integer.toBinaryString(-3));
System.out.println(0b11111111111111111111111111111101);
System.out.println(0b11111111111111111111111111111101 & 2047);
```

其中11111111111111111111111111111101是-3的补码，与2047 按位与之后，得到的结果是正数2045！可以自己试验一下。


然后继续看if (indexArrays[diff & indexArrayMax] != 0)，如果没找，也就是数字对应的位置标记数组值为0，那么

indexArrays[nums[i] & indexArrayMax] = i + 1;

说明此位数字（不是差）之前没有计算过，那么它的下标位置+1处理，防止i=0的时候与初始值0区分不开。

反之，如果if (indexArrays[diff & indexArrayMax] != 0)成立，那么说明 nums[i] = diff之前有记录，就直接取其记录对应的下标-1，就是原始输入数组的位置了。 

总结，通过额外开空间和将正负数利用补码转化成0-2047之间的正数进行位置记录，省去了一步判断，而且按位与相当于做了一个快速哈希，极大的提高了运行速度。所以，这个解法是目前是最快的。

说说缺点，无用的内存开销比较大



# 方法一 + 方法三

利用了方法1的Map去减少数组的内存开销，主体算法还是方法三的：
```
int indexArrayMax = 2047;
Map<Integer, Integer> map = new LinkedHashMap<>(nums.length);
int diff = 0;
Integer tIdx = 0;
for (int i = 0; i < nums.length; i++) {
    diff = target - nums[i];
    tIdx = map.get(diff & indexArrayMax);
    if ( tIdx != null) {
        return new int[] { tIdx - 1, i };
    }
    map.put(nums[i] & indexArrayMax,i + 1);
}
throw new IllegalArgumentException("No two sum value");
```

运算时间有所延长，3ms，但是内存空间消耗只有37.5MB。注意为了考虑Map的效率和空间，这里使用了LinkedHashMap而不是HashMap。而且，注意空间大小是nums。length，防止最坏情况下不够。

实测了2048，运算时间6ms，内存也上涨到了39MB以上。所以Map空间大小，对运算效能还是又很大影响的。





