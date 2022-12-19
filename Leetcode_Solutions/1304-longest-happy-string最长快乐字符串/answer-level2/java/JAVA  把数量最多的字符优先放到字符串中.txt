1.排序
2.判断是否所有字符都能用完。
我们假设数量最多的字符为a：
2.1不能用完。那么直接aabaabaacaa...直到bc用完即可。
2.2可以用完。先放aab，此时如果再放一个b还能全部用完就再放一个b如果不能就不放。直到abc全部用完即可。

2.2中判断条件为较少的两个字符的数量*2>=剩下最多的字符的数量

如：a:6,b:2,c:0
aab放完之后cnt(b)+cnt(c)=1,cnt(a)=4不满足上述要求所以不能再放b，进入下一个循环再放入aab，此时字符全部用完。

如：a:6,b:2,c:1
aab放完之后cnt(b)+cnt(c)=2,cnt(a)=4满足上述要求所以再放一个b变为aabb，进入下一个循环放入aac（此时没有b就用c代替），此时字符全部用完。

代码如下：
``` Java
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        MyChar[] myChars = new MyChar[] { new MyChar('a', a), new MyChar('b', b), new MyChar('c', c), };
        Arrays.sort(myChars);
        // for (int i = 0; i < myChars.length; i++) {
        // System.out.println(myChars[i].toString());
        // }
        MyChar myChar1 = myChars[0];
        MyChar myChar2 = myChars[1];
        MyChar myChar3 = myChars[2];
        StringBuilder sb = new StringBuilder();
        if ((myChar1.count + myChar2.count + 1) * 2 < myChar3.count) {
            while (myChar1.count + myChar2.count > 0) {
                // 如果最多的字符不能被全用用完，则每次增加两个最多的字符，再加一个其他的字符
                sb.append(myChar3.ch).append(myChar3.ch);
                if (myChar2.count > 0) {
                    sb.append(myChar2.ch);
                    myChar2.count--;
                } else {
                    sb.append(myChar1.ch);
                    myChar1.count--;
                }
            }
            // 最后再加上两个最多的字符
            sb.append(myChar3.ch).append(myChar3.ch);
            return sb.toString();
        } else {
            // 如果所有字符都能被用完，先用2个最多的字符，
            // 第二、三个字符就要考虑此时字符能否被都用完，如果用了第二（三）个字符之后，最多的字符不能被用完那么就不用。
            while (myChar1.count + myChar2.count + myChar3.count > 0) {
                // 最多的字符
                for (int i = 0; i < 2; i++) {
                    if (myChar3.count > 0) {
                        sb.append(myChar3.ch);
                        myChar3.count--;
                    }
                }
                // 第二多的字符
                for (int i = 0; i < 2; i++) {
                    if (myChar2.count > 0 && (myChar2.count + myChar1.count) * 2 >= myChar3.count) {
                        sb.append(myChar2.ch);
                        myChar2.count--;
                    }
                }
                // 最少的字符
                for (int i = 0; i < 2; i++) {
                    if (myChar1.count > 0 && (myChar1.count + myChar2.count) * 2 >= myChar3.count) {
                        sb.append(myChar1.ch);
                        myChar1.count--;
                    }
                }
            }
            return sb.toString();
        }
    }
}

private class MyChar implements Comparable<MyChar> {
    char ch;
    int count;

    public MyChar(char ch, int count) {
        this.ch = ch;
        this.count = count;
    }

    @Override
    public int compareTo(MyChar o) {
        MyChar other = o;
        return this.count - other.count == 0 ? other.ch - this.ch : this.count - other.count;
    }

    @Override
    public String toString() {
        return "'" + ch + "': " + count;
    }
}
```
