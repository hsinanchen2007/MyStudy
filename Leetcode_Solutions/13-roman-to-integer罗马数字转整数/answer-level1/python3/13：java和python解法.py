java用的是switch建立联系，把对应的数字按照顺序放置在一个新的List中。之后，从左往右判断，随后如果是左边小于右边，则将右边减去左边并将结果替代两个本身的值，否则保持不变，最后对List所剩的元素进行累加。
python3参考了用户Shao的思路，从右往左判断，简化了代码。

```java []
public int romanToInt(String s) {
        ArrayList<Integer> sToInteger = new ArrayList<Integer>();
        for (int i = 0; i < s.length(); i++) {
            String temp = s.substring(i, i + 1);
            switch(temp) {
                case("I"): sToInteger.add(1);break;
                case("V"): sToInteger.add(5);break;
                case("X"): sToInteger.add(10);break;
                case("L"): sToInteger.add(50);break;
                case("C"): sToInteger.add(100);break;
                case("D"): sToInteger.add(500);break;
                case("M"): sToInteger.add(1000);break;
            }
        }
        int sum = 0;
        for (int j = 0; j < sToInteger.size() - 1; j++) {
            if (sToInteger.get(j) < sToInteger.get(j + 1)) {
                sum = sToInteger.get(j + 1) - sToInteger.get(j);
                sToInteger.set(j, sum);
                sToInteger.remove(j + 1);
            }
        }
        sum = 0;
        for (Integer o : sToInteger) sum = sum + o;
        return sum;

    }
```
```python []
def romanToInt(s: str) -> int:
    dic = {"I":1,"V":5, "X":10,"L":50,"C":100,"D":500,"M":1000 }
    prev = 0
    temp = 0
    result = 0
    for o in reversed(s):
        temp =  dic.get(o)
        if prev > temp:
            result -= temp
        else:
            result += temp
        prev = temp
    return result
```


