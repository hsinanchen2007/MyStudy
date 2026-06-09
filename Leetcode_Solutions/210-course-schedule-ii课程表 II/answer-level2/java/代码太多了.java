


class Solution {


    public int[] findOrder(int numCourses, int[][] prerequisites) {
        if (prerequisites.length == 0){
            int[] a = new int[numCourses];
            for (int i = 0;i < numCourses;i ++){
                a[i] = i;
            }
            return a;
        }

        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0;i < prerequisites.length;i ++){
            int[] prereq = prerequisites[i];
            int key = prereq[1];
            int val = prereq[0];
            if (map.get(key) == null){
                map.put(key, 0);
            }
            if (map.get(val) == null){
                map.put(val, 1);
            }else{
                map.put(val, map.get(val) + 1);
            }
        }

        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0;i < numCourses;i ++){
            if (map.get(i) == null){
                list.add(i);
            }
        }
        Stack<Integer> stack = new Stack<>();

        if (canFinishII(prerequisites, map, stack, list)){
            Integer[] result = (Integer[])list.toArray(new Integer[list.size()]);
            int[] re = new int[result.length];
            for (int i = 0;i < result.length;i ++){
                re[i] = result[i];
            }
            return re;
        }else{
            return new int[0];
        }
    }
    
    public Boolean canFinishII(int[][] prerequistes, HashMap<Integer, Integer> map, Stack<Integer> stack, ArrayList<Integer> list) {
        map = getCourseValZero(map, stack);
        if (stack.size() == 0 && map.size() != 0) {
            return false;
        }
        while (!stack.isEmpty()) {
            int topVal = stack.pop();
            list.add(topVal);
            for (int i = 0; i < prerequistes.length; i++) {
                int key = prerequistes[i][1];
                int val = prerequistes[i][0];
                if (key == topVal) {
                    map.put(val, map.get(val) - 1);
                }
            }
        }
        if (map.size() != 0) {
            return canFinishII(prerequistes, map, stack, list);
        }
        return true;
    }

    public HashMap<Integer, Integer> getCourseValZero(HashMap<Integer, Integer> map, Stack<Integer> stack){
        HashMap<Integer, Integer> newMap = new HashMap<>();
        Set<Integer> keySet = map.keySet();
        Iterator<Integer> iterator = keySet.iterator();
        while (iterator.hasNext()){
            int key = iterator.next();
            int val = map.get(key);
            if (val == 0){
                stack.push(key);
            }else{
                newMap.put(key, val);
            }
        }
        return newMap;
    }
}