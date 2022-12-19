执行用时 :5 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :35.8 MB, 在所有 Java 提交中击败了100.00%的用户

思路：看到这个问题的时候，第一想法就是回溯，奈何一直超时，然后一路调试优化，从超时到2000+ms再到18ms最后到5ms，最终优化的逻辑如下
1.由于技能req_skills最多16个，则可以用二进制1，10，100...来表示从第一个到最后一个技能，由此可以将员工技能转换为对应第数字。
2.若存在两个员工技能重复可以去重，或者一员工技能是另外员工技能真子集，则该员工必不在最优解中，去除该员工，从而提高回溯效率
3.如果该员工集合中存在无交集员工（和其他所有员工技能不重复），那么该员工一定在最终解中，则可以得出无交集员工集合作为解的子集。
4.判断无交集员工技能是否是解，若是，则肯定是最优解，否则说明还缺少其他员工，则可以根据该集合员工数量+1来作为最小回溯深度来进行回溯，从而降低回溯深度。
5.对员工技能数peopleSkillNums进行排序，为了加快查找速度（主要为了对员工技能逐个匹配，例如匹配下一个技能员工时，只要已匹配技能中没有包含该技能，则添加）
6.从最小回溯深度开始回溯，对技能数进行或运算，若有解，则肯定是最优解，直接结束，若无解，则回溯深度+1，继续回溯

```
    //成员技能对应二进制数字都数组下标
    private int[] peopleSubscript;

    //当前递归深度
    private int currentDepth = 0;

    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int[] result = null;
        int skillLen = req_skills.length, mustSkill = (1 << skillLen) - 1, peopleSize = people.size();
        //技能对应二进制，用1，10，100来表示
        Map<String, Integer> skillMap = new HashMap<String, Integer>(skillLen << 1);
        for (int i = 0; i < skillLen; i++) {
            skillMap.put(req_skills[i], 1 << i);
        }
        //员工技能对应二进制数
        int[] peopleSkillNums = new int[peopleSize];
        peopleSubscript = new int[1 << skillLen];
        for (int i = 0; i < people.size(); i++) {
            int skillNum = 0;
            List<String> skills = people.get(i);
            for (String skill : skills) {
                skillNum += skillMap.get(skill);
            }
            peopleSkillNums[i] = skillNum;
            peopleSubscript[skillNum] = i;
        }
        //技能或运算结果
        int comSkills = 0;
        //和其他所有员工没交集对应员工数量
        int aloneCount = 0;
        //和其他所有员工没交集对应员工数组下标
        int[] noIntersectionArr = new int[skillLen];
        for (int i = 0; i < peopleSize; i++) {
            if (peopleSkillNums[i] == 0) {
                continue;
            }
            //是否无交集
            boolean isNoIntersection = true;
            for (int j = 0; j < peopleSize; j++) {
                if (peopleSkillNums[j] == 0 || i == j) {
                    continue;
                }
                //重复的，去重
                if (peopleSkillNums[i] == peopleSkillNums[j]) {
                    peopleSkillNums[j] = 0;
                    continue;
                }
                //若一个员工技能是另外一个员工子集，则必定不在最优解中，去除
                if ((peopleSkillNums[i] | peopleSkillNums[j]) == peopleSkillNums[j]) {
                    peopleSkillNums[i] = 0;
                    isNoIntersection = false;
                    break;
                } else if ((peopleSkillNums[i] | peopleSkillNums[j]) == peopleSkillNums[i]) {
                    peopleSkillNums[j] = 0;
                    continue;
                }
                if ((peopleSkillNums[i] & peopleSkillNums[j]) != 0) {
                    isNoIntersection = false;
                    break;
                }
            }
            //无交集员工提前保存，方便之后回溯（降低后续回溯深度）
            if (isNoIntersection) {
                comSkills |= peopleSkillNums[i];
                noIntersectionArr[aloneCount] = peopleSubscript[peopleSkillNums[i]];
                peopleSkillNums[i] = 0;
                aloneCount++;
            }
        }
        //员工技能数字排序
        Arrays.sort(peopleSkillNums);
        //最小回溯深度，由小到大，则第一个得到结果就为最优解
        int minDepth = aloneCount;
        //若无交集员工技能组成等于必须技能，则输出结果，否则开始回溯深度+1
        if (comSkills == mustSkill) {
            result = new int[aloneCount];
            System.arraycopy(noIntersectionArr, 0, result, 0, aloneCount);
            return result;
        } else {
            minDepth++;
        }
        //从minDepth回溯深度开始回溯，noIntersectionArr肯定在该结果中，回溯深度从无交集员工数量开始
        for (int i = minDepth; i < skillLen; i++) {
            currentDepth = i;
            result = new int[i];
            System.arraycopy(noIntersectionArr, 0, result, 0, aloneCount);
            if (addNextPeople(mustSkill, comSkills, result, peopleSkillNums, aloneCount)) {
                break;
            }
        }
        return result;
    }

    private boolean addNextPeople(int mustSkill, int comSkills, int[] result, int[] peopleSkillNums, int count) {
        //判断是否为解
        if (mustSkill == comSkills) {
            return true;
        }
        //大于回溯深度，则不存在
        if (count >= currentDepth) {
            return false;
        }
        for (int i = peopleSkillNums.length - 1; i >= 0; i--) {
            int skillNum = peopleSkillNums[i];
            //由于排序，则技能为0则后续都为0，直接结束
            if (skillNum == 0) {
                break;
            }
            //组合技能已包含该技能，则跳过
            if ((comSkills | skillNum) == comSkills) {
                continue;
            }
            result[count] = peopleSubscript[peopleSkillNums[i]];
            peopleSkillNums[i] = 0;
            if (addNextPeople(mustSkill, comSkills | skillNum, result, peopleSkillNums, count + 1)) {
                return true;
            }
            peopleSkillNums[i] = skillNum;
        }
        return false;
    }
```
