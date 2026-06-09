看了一下大家的解法，基本上都是把所有可能的组合都放进HashMap，然后遍历字符串的时候，优先查找两位数的组合是否存在，再判断一位的。但是这样既增加了多余的内存来存储组合，并且逻辑方面也不简单。
以下是我的算法，大神轻喷：
把基础的罗马数字添加到HashMap中，遍历字符串，同时分别取出后面两位的对应整数，判断如果后面位数的值比前面的值小，那么就在总数上加上前面的数值，否则就减去前面的数值，代码如下：
```
    public int romanToInt(String s) {
        // 算法一：判断后面数值是否大于前面
        Map<Character, Integer> romaNumber = new HashMap<>();
        romaNumber.put('I', 1);
        romaNumber.put('V', 5);
        romaNumber.put('X', 10);
        romaNumber.put('L', 50);
        romaNumber.put('C', 100);
        romaNumber.put('D', 500);
        romaNumber.put('M', 1000);

        int firstValue = 0;
        int nextValue = 0;
        int sum = 0;

       for (int i = 0; i < s.length(); i++){
            firstValue = romaNumber.get(s.charAt(i));
            if (i == s.length()-1){
                sum += firstValue;
            }else {
                nextValue = romaNumber.get(s.charAt(i+1));
                if (firstValue >= nextValue){
                    sum += firstValue;
                }else{
                    sum -= firstValue;
                }
            }
        }
        return sum;
    }
```
