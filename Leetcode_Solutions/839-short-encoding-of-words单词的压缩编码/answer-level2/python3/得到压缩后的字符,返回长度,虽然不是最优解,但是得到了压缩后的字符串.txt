# 1将数组中的字符串翻转
# 2新数组排序
# 3依次遍历新数组,如果istring是i+1stirng的前缀,过滤,如果不是,将res += item + "#",

```
def minimumLengthEncoding( words) -> int:
    N = len(words)
    # 1将数组中的字符串翻转
    newConter = list()
    for item in words:
        newConter.append(item[::-1])
    # 2新数组排序
    newConter.sort()
    # 3依次遍历新数组,如果istring是i+1stirng的前缀,过滤,如果不是,将res += item + "#",
    res = ""
    for item in words:
        i = newConter.index(item[::-1])
        if i+1 < N and newConter[i+1].startswith(newConter[i]):
            continue
        else:
            res += item + "#"
    return len(res)

if __name__ == "__main__":
    arr = ["time","me","line"]
    str = minimumLengthEncoding(arr)
    print(str)

```