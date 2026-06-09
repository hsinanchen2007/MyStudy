### 思路：
- 本题涉及`tomatoSlices`和`cheeseSlices`两个量，而两种汉堡的数量恰是两种材料的线性组合，故考虑将题目抽象成矩阵：
$$
\left[
 \begin{matrix} 
   4 & 2 \\
   1 & 1 
  \end{matrix} 
\right]

\left[
 \begin{matrix}
  x \\
  y
 \end{matrix}
\right]=


\left[
 \begin{matrix}
  tomatoSlices \\
  cheeseSlices
 \end{matrix}
\right]
$$

其中，x是巨无霸汉堡的数量，y是皇堡的数量。
若符合实际情况，则x,y皆是正整数。通过构造逆矩阵来求解：

$$
\left[
 \begin{matrix}
  x \\
  y
 \end{matrix}
\right]=


\left[
 \begin{matrix}
 \frac{1}{2} & -1 \\
 -\frac{1}{2} & 2
 \end{matrix}
\right]

\left[
 \begin{matrix}
  tomatoSlices \\
  cheeseSlices
 \end{matrix}
\right]=

\left[
 \begin{matrix}
  \frac{1}{2}tomatoSlices - cheeseSlices \\
  -\frac{1}{2}tomatoSlices + 2cheeseSlices
 \end{matrix}
\right]
$$
对结果进行如上限制可得：`tomatoSlices`必须是偶数，且`2*cheeseSlices <= tomatoSlices <= 4*cheeseSlices`。
由数学结论进行编码：
```python
def numOfBurgers(tomatoSlices, cheeseSlices):
    return [tomatoSlices // 2 - cheeseSlices, - tomatoSlices // 2 + 2*cheeseSlices] \
        if not tomatoSlices % 2 and 2 * cheeseSlices <= tomatoSlices <= 4 * cheeseSlices else []  
```
