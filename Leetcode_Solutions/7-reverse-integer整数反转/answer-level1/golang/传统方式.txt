func reverse(x int) int {
    sum:=0
    n:=0
    b:=0
    a:=[]int{}
    tag:=0
    
    if x<0{
        tag=1
        x=-x
    }
   
    for x>0{
        b=x%10
        a=append(a,b)
        x=x/10
        sum++ 
    }
    
        for i:=sum-1;i>=0;i--{
		n+=a[i]*int(math.Pow10(sum-1-i))
        
    }
    
    if tag==1{
        n=-n
    }
    
     if  n< -(1<<31) || n>(1<<31)-1{
        n=0
    }


    return n
    
    
}