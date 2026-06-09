首先先感谢一下大神@1Q一个小朋友 提供的思路。原本我是用的list去重，但是时间效率实在感人。后来看到大神思路茅塞顿开，写一下自己理解。先上图和代码
![屏幕快照 2019-11-26 上午11.41.04.png](https://pic.leetcode-cn.com/d713dac99575c5ba6d0f1b97c4bdd6e3506dc817724a417a4ece224e1a4384cc-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-11-26%20%E4%B8%8A%E5%8D%8811.41.04.png)

代码：
```
  public  String getHint1(String secret, String guess) {
        int a = 0, b = 0, i;
        int[] secretbucket = new int[10];
        int ilength = guess.length();
        for (i = 0; i < ilength; i++) {
            if (secret.charAt(i) == guess.charAt(i))
                a++;
            else {
                secretbucket[secret.charAt(i) - '0']++;
            }
        }
        for (i = 0; i < ilength; i++) {
            if ((secret.charAt(i) != guess.charAt(i)) && secretbucket[guess.charAt(i) - '0'] > 0) {
                b++;
                secretbucket[guess.charAt(i) - '0']--;
            }
        }
        return "" + a + "A" + b + "B";
    }
```

因为比较的是数字，有secret和guess两串，
需求点一：找出同样位置相同的数字；
需求点二：相同但位置不同的数字；
我们可以分步进行：
第一步找出相同位置且数值相同的。这个简单，直接一次遍历即可，然后用一个int型数值来计数。
第二步找出相同但位置不同的数字。这个如果按照原有字符串的顺序找就很麻烦，不如换个思路，
去除满足需求点一的数字之后，剩下的都是相同位置上数值不一样的数字，此时求b的时候就无关顺序了。但是求‘奶牛‘b的时候要求以secret为准（毕竟人家让你猜，人家是裁判嘛），并且刚才我提到，此时已经无关顺序了，这样我们需要一种方式能对secret中数据进行分类计数，再那这个统计好的数去guess中去查，对上一个就b++一次，然后把这个计数--一次。那如何实现呢？那就是bucket桶。那我们就造’桶‘吧。那造多少个桶呢？我们看看有多少种数字？0-9一共10种，那就造10个桶，我们new int[10],数组下标对应桶的类型，在代码中第一次遍历的时候，‘公牛’a条件不满足的时候我们开始给‘桶’加‘水’加一，然后在第二次遍历时，过滤掉guess中满足‘公牛’的数据，然后以guess中数据去一群桶中找到对应的桶，看里面有没有水secretbucket[guess.charAt(i) - '0'] > 0，有的话就b++，然后把水舀出来secretbucket[guess.charAt(i) - '0']--， 一共能舀出来多少次，b就等于多少。

