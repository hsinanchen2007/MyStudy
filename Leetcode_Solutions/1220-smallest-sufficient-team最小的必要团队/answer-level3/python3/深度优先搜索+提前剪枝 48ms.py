
```
class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        # 初始化
        req_skills_set = set(req_skills)
        skills_dict = {x: [] for x in req_skills}
        for i, p in enumerate(people):
            for skill in p:
                if skill in req_skills_set:
                    skills_dict[skill].append(i)
        skills_set_dict = {k: set(v) for k, v in skills_dict.items()}
        # 排序，更早搜索到最终解
        for k, v in skills_dict.items():
            v.sort(key=lambda i:len(people[i]))
        req_skills.sort(key=lambda x:len(skills_dict[x]))
        
        # dfs
        res = len(req_skills)
        res_people = [x[0] for x in skills_dict.values()]
        now_people = []
        s = [[0, skills_dict[req_skills[0]]]]
        while len(s) > 0:
            if len(s[-1][-1]) > 0:
                p = s[-1][0]+1
                person = s[-1][-1].pop()
                # 剪枝
                if len(now_people) >= res-1:
                    s.pop()
                    now_people.pop()
                    continue
                now_people.append(person)
                now_people_set = set(now_people)
                while p<len(req_skills) and len(skills_set_dict[req_skills[p]] & now_people_set) > 0:
                    p += 1
                if p == len(req_skills):
                    if len(now_people) <= res:
                        res = len(now_people)
                        res_people = now_people[:]
                    now_people.pop()
                else:
                    s.append([p, skills_dict[req_skills[p]][:]])
            else:
                s.pop()
                if len(now_people) == 0:
                    break
                now_people.pop()
        return res_people
```
