实现起来很简单：
```c# []
public int HammingDistance(int x, int y) {
        var r=x^y;
        var res=Convert.ToString(r,2);
        int k=0;
        for(var i=0;i<res.Length;i++){
            if(res[i]=='1'){
                k++;
            }
        }
        return k;
    }
```

