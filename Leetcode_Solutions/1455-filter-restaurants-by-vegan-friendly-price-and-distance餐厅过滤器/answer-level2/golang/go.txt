### 解题思路
此处撰写解题思路

### 代码

```golang
func filterRestaurants(restaurants [][]int, veganFriendly int, maxPrice int, maxDistance int) []int {
    data := make([]elem,0)

    for i:=0; i < len(restaurants); i++ {
        if restaurants[i][3] > maxPrice || restaurants[i][4] > maxDistance {
            continue
        }
        if veganFriendly == 1{
            if restaurants[i][2] != 1 {
                continue
            }
        }
        e := elem{
            id:     restaurants[i][0],
            rating: restaurants[i][1],
        }
        data = append(data, e) 
        //fmt.Println(data)
    } 

    sort.Sort(IntSlice(data)) 

    result := make([]int,len(data))
    for i := range result {
        result[i] = data[i].id
    }

    return result
}


type elem struct {
    id int 
    rating int
}
 
type IntSlice []elem
 
func (s IntSlice) Len() int { return len(s) }
func (s IntSlice) Swap(i, j int){ s[i], s[j] = s[j], s[i] }
func (s IntSlice) Less(i, j int) bool { 
    if s[i].rating != s[j].rating {
        return s[i].rating > s[j].rating
    }else {
        return s[i].id > s[j].id
    }
     
}
```