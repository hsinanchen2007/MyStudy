 

 ```
class CQueue {
        Stack<Integer> s1; 
        Stack<Integer> s2; 
        public CQueue() {
        s1 = new Stack<Integer>();
        s2 = new Stack<Integer>();
         
        }

        public void appendTail(int value) {
            s1.push(value);

        }

        public int deleteHead() {
            if (s2.size() <= 0) {
                while (s1.size() > 0) {
                    s2.push(s1.pop());
                }
            }
            if (s2.size() == 0) {
                return -1;
            }
           return s2.pop();

        }
 }
```
