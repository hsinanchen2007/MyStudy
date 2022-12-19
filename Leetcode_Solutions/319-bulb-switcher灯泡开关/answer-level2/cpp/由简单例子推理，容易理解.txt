```yaml
1 2 3 4 5 6 7 8 9 10 11 12  
  2   4   6   8   10    12  
    3     6     9       12  
      4       8         12  
        5         10      
          6             12  
            7 8 9 10 11 12  
```
仔细看，会发现只有在平方数地方的灯泡会亮着，可以理解为如果是平方数，平方因子只会经过一次。
所有，只要判断有几个平方数就可以了。
```
    int bulbSwitch(int n) {
        int index=1;
        for(int i=1; i<=n; i++) {
            if(index*index ==i) {
                index++;
                if(index*index>n) break;
            }
        }
        return index-1;
    }
```
仔细一想，由'if(index*index>n) break;' 这句可以想到求sqrt(n)就可以了，简化后代码只有一行
```
    int bulbSwitch(int n) {
        return sqrt(n);
    }
```

