```
func getLeastNumbers(arr []int, k int) []int {
    goal:=[]int{}
    goal=arr
    n:=len(goal)
    
    for j:=0;j<k;j++{
    for i:=n-1;i>=1;i--{
        if goal[i]<goal[i-1]{
            goal[i],goal[i-1]=goal[i-1],goal[i]
        }    
    }}
     return goal[0:k]
}
```
