
![image.png](https://pic.leetcode-cn.com/01fb72bd329aceff50d4a6f71bdf9eac8eb2fae17d1c3693cd16247549b74fbd-image.png)

代码核心是用递归生成所有可能的组合数。每一个组合数用数组记录。所有的组合数形成一个组合数组列表作为类属性。

生成一个组合数的形象解释如下：
如果要生成3位组合数，位上最大值5。第一位不管三七二十一轮流1到5，当第一位是i时，第二位的最小值至少要比第一位大1，也就只能轮流i+1到5，当第二位是j时，第三位的最小值是j+1，也就只能轮流j+1~5。

以此类推，如果要生成n位组合数，位上最大值m（m>=n）。第一位不管三七二十一轮流1到m，当第一位是i时，第二位的最小值至少要比第一位大1，也就只能轮流i+1到m，后续位数依次类推。

```
generate(存新生成的组合数的数组，当前需要生成的位数，位上的最小值, 位上的最大值) {
    for(int i =位上的最小值; i<位上的最大值; i++){
        存新生成的组合数的数组的当前生成的位数 = i
        generate(存新生成的组合数的数组，当前需要生成的位数+1, i+1, 位上的最大值)
    }
}

递归终止条件是，当前生成的位数>需要的位数，返回前，把此次新生成结果的副本保存。
generate(存新生成的组合数的数组，当前需要生成的位数，位上的最小值, 位上的最大值) {
    if(当前需要生成的位数 == 存新生成的组合数的数组的长度){
        把新生成的组合数加入结果集列表
        返回
    }
    for(int i =位上的最小值; i<位上的最大值; i++){
        将存新生成的组合数的数组的当前生成的位数 置为 i
        generate(存新生成的组合数的数组，当前需要生成的位数-1, i+1, 位上的最大值)
    }
}
```




提一下一些细节上的巧合：字符串是数组，所以组合数的从小遍历到大的生成方法无需更改，否则需循环递减。

组合数生成需注意以下一点：
位上最小值从0开始
位上的最大值固定为字符串的长度-1。

```
class CombinationIterator {

        String characters;
        int now = 0;
        List<int[]> comb;
        public CombinationIterator(String characters, int combinationLength) {
            generate(new int[combinationLength], 0,0, characters.length());
            this.characters = characters;
        }
        public String next() {
            int[] pos = comb.get(now);
            StringBuilder sb = new StringBuilder();
            for (int po : pos) {
                sb.append(characters.charAt(po));
            }
            now++;
            return sb.toString();
        }

        public boolean hasNext() {
            return now< comb.size();
        }


        public void generate(int[] pos, int p, int s, int len) {
            if(p>=pos.length){
                comb.add(Arrays.copyOf(pos, pos.length));
                return;
            }
            for(int i = s; i<len;i++){
                pos[p] = i;
                generate(pos,  p+1,i+1, len);
            }
        }
    }
```

细节控：注意构造器内清空结果集，双周赛就是结果集忘记在构造函数内清空了，导致此题未在11点59分提交成功。自己本机测试只能一次跑一个case，发现都行，但是提交总有莫名的让生成1位，我给出2位的结果，太紧张，导致没能在最后一分钟发现问题。