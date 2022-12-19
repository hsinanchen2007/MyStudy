### 执行用时1ms
本题需要统计两个数据：
1. 同时猜中数字和位置的次数，用A记录
2. 只猜中数字而位置不对的次数，用B记录

第一个数据的统计比较容易，只需遍历一次secret字符串每个字符，若guess中的字符位置和值都相同，则A++。
主要在于第二个数据的统计，只需注意一点，假设guess中含有3个数字x，而secret中只含有2个，则B应该为2。由此，我们需要知道secret中所有没被猜中数值和位置的数字有哪些，以及它们出现的次数，同理，我们也需要知道guess中这样的数字有哪些和它们出现的次数。
自然地，我们采用两个哈希表记录这两个字符串中这些多余的数字和它们出现的次数。由于数字只有0到9十个，所以用长度为10的int[]数组作为哈希表即可满足需求。在第一次循环中，对secret中没被猜中位置和数值的数字i，存放在哈希表int[] extra1中，次数extra1[i]++；对guess中没被猜中位置和数值的数字i，存放在哈希表int[] extra2中，次数extra2[i]++。
两个哈希表记录完成后，遍历哈希表，累加哈希表每个位置的Math.min(extra1[i], extra2[i])就能得到B。

时间复杂度：O(n)。需要遍历字符串每个字符。
空间复杂度：O(1)。哈希表大小固定为10，因为只有0到9十个数字。

代码

```java
class Solution {
    public String getHint(String secret, String guess) {
        int A = 0, B = 0;
        int[] extra1 = new int[10];
        int[] extra2 = new int[10];
        for(int i = 0; i < secret.length(); i++)
        {
            int a = secret.charAt(i) - '0';//注意数字和ASCII码之间的转换
            int b = guess.charAt(i) - '0';
            if(a == b)  A++;
            else
            {
                extra1[a]++;
                extra2[b]++;
            }   
        }
        for(int i = 0; i < 10; i++)
            B += Math.min(extra1[i], extra2[i]);
        return A + "A" + B + "B";
    }
}
```
### 优化
考虑将哈希表的数量由两个减少为一个。只有一个哈希表即一个int[]数组，作用是：多余数字还未使用的次数。
多余数字就是secret中所有没被猜中位置和数值的数字。而怎么使该数组实现这一作用呢?
times[a]++;
times[b]--;
这样一来，若有多余数字a，并且被b对应上，则视为使用一次。
若times[i]为负值，意为guess中的数字既没有才对位置也没有猜对数值，即secret中没有出现。
若times[i]为零，意为多余数字被使用完了，或者数字i不是多余数字。
若times[i]为正值，意为多余数字没被使用过，或没被使用完。
累加所有times[i]的正值，得到的和就是多余数字还剩余的使用次数。而我们需要的B就是已使用的次数。
问题迎刃而解，已使用的次数就是所有的数字的个数，减去非多余数字（位置和数值都被猜中的数）的个数，再减去多余数字的剩余使用次数，即得到多余数字已使用次数，即B。
B = secret.length() - A -sum;

代码

```java
class Solution {
    public String getHint(String secret, String guess) {
        int A = 0, B = 0;
        int[] times = new int[10];
        for(int i = 0; i < secret.length(); i++)
        {
            int a = secret.charAt(i) - '0';
            int b = guess.charAt(i) - '0';
            if(a == b)  A++;
            else
            {
                times[a]++;
                times[b]--;
            }
        }
        int sum = 0;
        for(int i = 0; i < 10; i++)
            if(times[i] > 0)    sum += times[i];
        B = secret.length() - A - sum;
        return A + "A" + B + "B";
    }
}
```
虽然少了一个哈希表，但内存消耗得到的优化并不明显。