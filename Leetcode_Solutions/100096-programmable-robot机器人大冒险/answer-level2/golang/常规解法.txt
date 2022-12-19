直接每次移动硬算的思路就不计了，超时，大家都懂。
题木的目的，抽象为：终点和障碍物坐标，是否在command的第n个执行周期的路径上。如果障碍物在，则失败；反之，并且终点在，则成功。其他情况均为失败 。
记录下整体思路：
（1）根据command字符串，可以计算出一个command执行周期中，x、y方向的总位移量。
（2）根据x、y，可直接计算出终点和各个障碍物点在第n个command周期中的相对坐标。
（3）直接根据command硬算，各个点在第n个command执行周期中，是否在command的移动路径上。这样每个点只需要计算一个command周期的运算量就行了。
（4）todo：待优化，将障碍物的各个点根据其坐标进行分类，在同一个command周期的点分为同一类，在计算时，同一类的障碍物坐标，可在一个command执行周期内就计算出。减少了重复计算。结果：
![image.png](https://pic.leetcode-cn.com/a13a944adcaf985b183051f09513ededd995ed2eff3cb92157da889e646783f6-image.png)
```
/*
直接每次移动硬算的思路就不计了，超时，大家都懂。
题木的目的，抽象为：终点和障碍物坐标，是否在command的第n个执行周期的路径上。如果障碍物在，则失败；反之，并且终点在，则成功。其他情况均为失败 。
记录下整体思路：
（1）根据command字符串，可以计算出一个command执行周期中，x、y方向的总位移量。
（2）根据x、y，可直接计算出终点和各个障碍物点在第n个command周期中的相对坐标。
（3）直接根据command硬算，各个点在第n个command执行周期中，是否在command的移动路径上。这样每个点只需要计算一个command周期的运算量就行了。
（4）todo：待优化，将障碍物的各个点根据其坐标进行分类，在同一个command周期的点分为同一类，在计算时，同一类的障碍物坐标，可在一个command执行周期内就计算出。减少了重复计算。
*/

func robot(command string, obstacles [][]int, x int, y int) bool {
    op:=map[string]int{
        "U":1,
        "R":0,
        }
    movex,movey:=calcuMove(command)//计算一个command周期的x、y方向的位移量
    
    if !reachGoal(movex,movey,x,y,command,op) {//先判断终点坐标是否是可达的
        return false
    }
    obstacles=filterObs(obstacles,[]int{x,y})//过滤掉在终点之后的障碍物
    return !reachObs(movex,movey,obstacles,command,op)//是否会碰到障碍物
}
//根据command计算出一个command周期的x、y位移。
func calcuMove(command string)(movex int ,movey int){
    for _,c:=range command{
        switch string(c){
            case "U":
                movey++
            case "R":
                movex++
        }
    }
    return movex,movey
}

//根据当前指令，进行移动。
func move(p[]int,command string,op map[string]int){
    pos:=op[command]
    p[pos]++
}

//计算des这个点，在一个command周期位移为xMove、yMove时，第n个command周期中，相对于第n个周期的相对坐标。
func calcuDesMove(xMove,yMove int,des []int) (result []int){
    step:=des[0]/xMove
    if step*yMove>des[1]{
        return nil
    }
    result=append(result,des[0]-step*xMove)
    result=append(result,des[1]-step*yMove)
    return result
}
//是否能从start移动至des
func move2Des(start ,des []int,command string,op map[string]int) bool{
 
        for _,c:=range command {
            if isReach(start,des[0],des[1]){//是否已经到达终点
                return true
            }
            move(start,string(c),op)//移动     
        }
        return false
}

//是否到达
func isReach(currentP []int,x,y int) bool{
    if currentP[0]==x&&currentP[1]==y{
        return true
    }
    return false
}

//能否碰到障碍物
func reachObs(movex,movey int ,obstacles [][]int,command string,op map[string]int)( bool){//待优化，每次都全遍历监测，其实没有必要，在同一个command周期内的点，在一次运算中就可以计算了。
    
    for _,obs:=range obstacles{
        relativeObs:=calcuDesMove(movex,movey,obs)
        if relativeObs==nil{
            continue
        }
        isMeetObs:=move2Des([]int{0,0},relativeObs,command,op)
        if isMeetObs {
            return true
        }
    }
    return false
}

func reachGoal(movex,movey int,dx,dy int,command string,op map[string]int) bool{
    relativeDes:=calcuDesMove(movex,movey,[]int{dx,dy})
    if relativeDes==nil{
        return false
    }
    return move2Des([]int{0,0},relativeDes,command,op)
}

//能否达到终点
func filterObs(obstacles [][]int,des []int) [][]int{
    newObs:=make([][]int,0)
    for _,obs:=range obstacles {
        if obs[0]>des[0]||obs[1]>des[1]{
            continue
        }
        newObs=append(newObs,obs)
    }
    return newObs
}
```
