1. 将p构建成有限状态机，主要是a* .*处理方式较复杂，见图
![WechatIMG36.jpeg](https://pic.leetcode-cn.com/36d7df5dcf1227ddfc2b55578c05eeb91bdeac07cf15099009d4902df84d4ed1-WechatIMG36.jpeg)
2. 遍历s，通过第一步构建的有限状态机来转移状态
3. 如果遍历完成，最后状态列表中有end标识的状态，那么就匹配到了，否则，没有匹配到

```
class Solution {
    public boolean isMatch(String s, String p) {
        State dfa = buildStateChain(p);
        Set<State> dfaSet = new HashSet<>();
        dfaSet.add(dfa);
        int index = -1;
        while(++index < s.length()){
            char ch = s.charAt(index);
            String input = String.valueOf(ch);
            Set<State> newStateSet = new HashSet<>();
            for(State state : dfaSet){
                List<State> newList = state.changeState(input);
                if(newList != null){
                    newStateSet.addAll(newList);
                }
            }
            dfaSet  = newStateSet;
            if(dfaSet.size() <= 0){
                break;
            }
        }

        boolean isMatch = false;
        for(State state : dfaSet){
            if(state.isEnd()){
                isMatch = true;
                break;
            }
        }

        return isMatch;
    }

      public State buildStateChain(String p){
        State start = new State();
        start.setStart(true);

        List<State> currentLevelStateList = Arrays.asList(start);
        for(int i = 0; i < p.length(); i++){
            char current = p.charAt(i);
            if(current == '*'){
                continue;
            }
            Character next = null;
            if(i < p.length() - 1){
                next = p.charAt(i + 1);
            }

            List<State> nextLevelStateList = new LinkedList<>();
            State nextState = new State();
            nextLevelStateList.add(nextState);
            String currentStr = String.valueOf(current);
            for(State currentState : currentLevelStateList) {
                currentState.addNextState(currentStr, nextState);

                // 如果是x* 这种形式的话，状态有个自循环，并且当前状态需要建立一个和下下个状态的关系
                if (next != null && next.equals('*')) {
                    nextLevelStateList.add(currentState);
                    nextState.addNextState(currentStr, nextState);
                }
            }

            currentLevelStateList = nextLevelStateList;
        }

        for(State currentState : currentLevelStateList) {
            currentState.setEnd(true);
        }

        return start;
    }

    class State{
        private boolean start;
        private boolean end;

        // 状态转移mapping
        private Map<String, List<State>> nextMap = new HashMap<>();

        public List<State> changeState(String input){
            List<State> result = new LinkedList<>();
            List<State> nextList = nextMap.get(input);
            if(nextList != null){
                result.addAll(nextList);
            }
            nextList = nextMap.get(".");
            if(nextList != null){
                result.addAll(nextList);
            }

//            List<State> forEmptyList = nextMap.get("");
//            if(forEmptyList != null){
//                result.addAll(forEmptyList);
//            }

            return result;
        }

        public boolean isStart() {
            return start;
        }

        public void setStart(boolean start) {
            this.start = start;
        }

        public boolean isEnd() {
            return end;
        }

        public void setEnd(boolean end) {
            this.end = end;
        }

        public void addNextState(String input, State next){
            List<State> nextList = nextMap.get(input);
            if(nextList == null){
                nextList = new LinkedList<>();
                nextMap.put(input, nextList);
            }
            nextList.add(next);
        }

    }
}
```

