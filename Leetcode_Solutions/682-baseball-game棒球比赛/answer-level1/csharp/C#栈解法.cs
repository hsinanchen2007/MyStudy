```
public int CalPoints(string[] ops) {
        var stack=new Stack<int>();
        for(var i=0;i<ops.Length;i++){
            var op=ops[i];
            switch(op){
                case "C":
                    stack.Pop();
                    break;
                case "D":
                    stack.Push(stack.Peek()*2);
                    break;
                case "+":
                    var t1=stack.Pop();
                    var t2=stack.Peek();
                    stack.Push(t1);
                    stack.Push(t1+t2);
                    break;
                default:
                    stack.Push(int.Parse(op));
                    break;
            }
            
        }
        int sum=0;
        while(stack.Count>0){
            sum+=stack.Pop();
        }
        return sum;
    }
```
