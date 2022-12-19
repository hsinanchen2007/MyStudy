题目最后一个用例的科目表是空的，所以无脑Left Join下去会失败

```
    Select S.student_id,S.student_name,SJ.subject_name,Count(E.student_id) As attended_exams
    From Students As S
    Join Subjects As SJ
    On 1=1
    Left Join Examinations As E
    On (S.student_id,SJ.subject_name)=(E.student_id,E.subject_name)
    Group By S.student_id,S.student_name,SJ.subject_name
    Order By S.student_id,SJ.subject_name
```
