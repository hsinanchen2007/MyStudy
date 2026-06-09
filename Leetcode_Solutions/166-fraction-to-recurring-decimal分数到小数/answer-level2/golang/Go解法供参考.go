```
func fractionToDecimal(numerator int, denominator int) string {
    sign := 1
    if (numerator > 0 && denominator < 0) || (numerator < 0 && denominator> 0) {
        sign = -1
    }
    desc := abs(numerator) / abs(denominator)
    unit := abs(numerator) % abs(denominator)
    res := ""
    if -1 == sign {
        res +="-"
    }
    res += strconv.Itoa(desc)
    if unit == 0 {
        return res
    }
    res += "."
    by := abs(denominator)
    deci := ""
    m := make(map[int]int)
    pos := 0
    for unit != 0 {
        if _,ok := m[unit]; ok {
            deci = deci[:m[unit]] + "("+ deci[m[unit]:] +")"
            return res+ deci
        }
        m[unit] = pos
        deci += strconv.Itoa(unit*10/by)
        unit = (unit*10) % by
        pos++
    }
    return res + deci
}

func abs(i int) int {
    if i > 0 {
        return i
    }
    return -i
}
```
