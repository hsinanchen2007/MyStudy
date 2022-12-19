![微信截图_20200110185242.png](https://pic.leetcode-cn.com/e2d673ee69a7fc7bd959550c95717f5d0249f55a797f61327c44caf9a1b53654-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200110185242.png)



### bytes
bytes

### bytes

```golang
func checkRecord(s string) bool {
    ac := 0
    lc := 0
    lllc := 0
    for _,r := range s{
        if byte(r) == 'A' {
            ac++
        }

        if byte(r) != 'L'  {
            lc = 0
        }else {
            lc++
        }

        if lc ==3 {
            lllc++
        }
    }
    return ac <= 1 && lllc == 0 
  }
```