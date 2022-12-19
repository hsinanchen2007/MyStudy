题目这个返回值应该是第n+1行吧？

在一个list上取值替换值进行计算，**需要通过一个中间值保存被替换的值**，因为该值还需要参加下一个数的运算。

```
public static List<Integer> generate(int rowIndex) {
        List<Integer> triangle = new ArrayList<>(rowIndex);
        if (rowIndex == 0) {
            return triangle;
        }
        triangle.add(1);
        for (int i = 1; i < rowIndex; i++) {
            int middle = 1;
            for (int j = 1; j < i && i > 1; j++) {
                int middle1 = triangle.get(j);
                triangle.set(j, middle + triangle.get(j));
                middle = middle1;
            }
            triangle.add(1);
        }
        return triangle;
    }
```







