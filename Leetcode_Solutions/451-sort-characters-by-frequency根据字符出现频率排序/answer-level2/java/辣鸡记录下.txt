### 解题思路
渣渣思路，主要是用了equal hashcode方法和compareTo
今天电话面试被问了这种类似的题，然后面试官很不屑的问我有没有接触过算法，，好吧，我确实没有，然后问完这题就把电话挂了。。
这个辣鸡做法复杂度啥的都爆表了，不推荐，我是为了做出来而做出来这道题，都和算法无关了

### 代码

```java
import java.util.*;

class Solution {
    public String frequencySort(String s) {
        String val = s;
        char[] chars = val.toCharArray();
        HashMap<Character, Num> map = new HashMap<>();
        for (char c : chars) {
            if (map.containsKey(c)) {
                Num num = map.get(c);
                num.incremenet();
            } else {
                map.put(c, new Num(c));
            }
        }
        Collection<Num> nums = map.values();
        TreeSet<Num> set = new TreeSet<>(nums);
        StringBuffer sb = new StringBuffer();
        for (Num num : set) {
            char charNum = num.getCharNum();
            for (int i = 0; i < num.getFrequency(); i++) {
                sb.append(charNum);
            }
        }
        return sb.toString();
    }


}
class Num implements Comparable {
    private Character charNum;

    private Integer frequency = 1;

    public Num(char charNum, int frequency) {
        this.charNum = charNum;
        this.frequency = frequency;
    }

    public Num(char charNum) {
        this.charNum = charNum;
    }

    public void incremenet() {
        this.frequency++;
    }

    public Character getCharNum() {
        return charNum;
    }

    public void setCharNum(char charNum) {
        this.charNum = charNum;
    }

    public Integer getFrequency() {
        return frequency;
    }

    public void setFrequency(Integer frequency) {
        this.frequency = frequency;
    }

    @Override
    public int compareTo(Object o) {
        Num num = (Num) o;
        int i = num.getFrequency() - this.getFrequency();
        return i != 0? i : num.getCharNum().compareTo(this.getCharNum());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null) return false;
        Num num = (Num) o;
        return charNum .equals(num.charNum) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(charNum);
    }

    @Override
    public String toString() {
        return "Num{" +
                "charNum=" + charNum +
                ", frequency=" + frequency +
                '}';
    }
}
```