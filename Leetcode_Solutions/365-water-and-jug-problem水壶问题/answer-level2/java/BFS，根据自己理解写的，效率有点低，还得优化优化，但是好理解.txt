    
    class Solution {
        public class State{
            int x;
            int y;
            public State(int x, int y) {
                this.x = x;
                this.y = y;
            }
            
            @Override
            public int hashCode() {
                return Objects.hash(x, y);  // 相同x与y的，返回相同的hash值
            }
            
            @Override
            public boolean equals(Object obj) {
                if(obj == null) {
                    return false;
                }
                State temp = (State)obj;
                if(temp.x != this.x) {
                    return false;
                }
                if(temp.y != this.y) {
                    return false;
                }
                return true;
            }
            
        }

        public boolean canMeasureWater(int x, int y, int z) {
            if(z == 0) {
                return true;
            }
            if(x + y < z) {
                return false;
            }
            Queue<State> queue = new LinkedList<>();
            HashSet<State> set = new HashSet<>();
            State start = new State(0, 0);  // 刚上来两个容器都没有水
            queue.add(start);
            set.add(start);
            while(!queue.isEmpty()) {
                State temp = queue.poll();
                int curx = temp.x;
                int cury = temp.y;
                if(curx + cury == z) {
                    return true;
                }
                List<State> nextStates = getNextStates(temp, x, y);
                for(int i = 0;i < nextStates.size();i++) {
                    if(!set.contains(nextStates.get(i))) {
                        queue.add(nextStates.get(i));
                        set.add(nextStates.get(i));
                    }
                }
            }
            return false;
        }

        public List<State> getNextStates(State state, int x, int y) {
            List<State> next = new ArrayList<>();
            int curx = state.x;
            int cury = state.y;
            next.add(new State(x, cury)); // A full
            next.add(new State(curx, y)); // B full
            next.add(new State(0, cury)); // A empty
            next.add(new State(curx, 0)); // B empty
            // A -> B
            if(curx >= y - cury) {
                next.add(new State(curx - (y - cury), y));
            }else {
                next.add(new State(0, curx + cury));
            }
            // B -> A
            if(cury >= x - curx) {
                next.add(new State(x, cury - (x - curx)));
            }else {
                next.add(new State(curx + cury, 0));
            }
            return next;
        }

    }