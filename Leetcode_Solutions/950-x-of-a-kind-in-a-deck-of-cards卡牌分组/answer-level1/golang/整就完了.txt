### 解题思路
此处撰写解题思路

1、辗转相除法求最大公约数
2、求一组数的最大公约数，先把前两个数的最大公约数求出来，然后用这个最大公约数和这组数的后面每一个数求最大公约数
3、一把梭求完一组数的最大公约数后，如果公约数是1，就false
4、注意[1,1,1] 也是 true

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {

    if len(deck) == 1{
        return false
    }

    intMap := make(map[int]int)
    for _,v := range deck{
        intMap[v]++;
    }

    var intSlice []int

    for _, v := range intMap {
        intSlice = append(intSlice, v)
    }

    if len(intSlice) == 1 {
        return true
    }

    var tmp int;
    tmp =  gcd(intSlice[0], intSlice[1]);
    for i:=2; i < len(intSlice); i++{
        tmp = gcd(intSlice[i], tmp) 
    }

    if tmp == 1 {
        return false
    }
    for _, v := range intSlice {
        if v % tmp != 0 {
            return false
        }
    }


    return true;
}

func gcd(a, b int) int {
    if(a % b == 0) {
        return b;
    }
    return gcd(b, a % b)
}

```