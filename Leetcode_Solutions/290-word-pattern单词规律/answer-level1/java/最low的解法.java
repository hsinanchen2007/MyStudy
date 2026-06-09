1、首先我看题解很多都是用map来做的，但我是用HashSet来辅助解题的。这题可以有多种写法，我写了个最low的，开始看到这题目的时候，突然想到了一个数据结构Set，因为Set当中不能存储重复的元素，那么这样的话我就可以通过Set把pattern和str有多少种不同元祖求出来了，这样的话如果两个字符串的种类个数都不同的话，直接返回false。
```
    /*读取分割字符串有多少种类*/
    public int splitword(String str){
        String[] count = str.split(" ");
        //使用set，由于set不具备重复存储功能，那么只是想知道一个字符串种类数就可以用set。
        Set<String> result = new HashSet<>();
        for (int i = 0; i < count.length; i++) {
            result.add(count[i]);
        }
        return result.size();
    }

    /*读取pattern有多少种类*/
    public int splitpattern(String str){
        Set<String> result = new HashSet<>();
        for (int i = 0; i < str.length(); i++) {
            char a = str.charAt(i);
            result.add(a+"");
        }
        return result.size();
    }
```
2、接下来就是比较了，先分割字符串，获取子字符串，然后用两遍循环去遍历patter和str的内容，全部比较一遍就成了。
```
    public boolean wordPattern(String pattern, String str) {
        //首先判断种类数是否相同，如果不同直接返回false
        if (splitpattern(pattern)!=splitword(str)){
            return false;
        }
        String[] x = str.split(" ");
        //长度都不同直接返回false;
        if (x.length!=pattern.length()){
            return false;
        }
        for (int i = 0; i <x.length ; i++) {
            String start = x[i];
            char pa = pattern.charAt(i);
            for (int j = i+1; j < x.length; j++) {
                if (pa==pattern.charAt(j)){
                    if (!start.equals(x[j])){
                        return false;
                    }
                }
            }
        }
        return true;
    }
```
