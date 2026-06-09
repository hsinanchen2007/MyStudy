思路是每2位用int转10进制然后加8后除以17，然后用hex转16进制，复制2遍，连接在一起
```python
return '#' + ''.join(map(lambda x: hex((int(x, 16) + 8) // 17)[2:] * 2, (color[i: i + 2] for i in range(1, 7, 2))))
```
