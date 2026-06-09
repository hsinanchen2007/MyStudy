```python
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        def process_email(email: str) -> str:
            index = email.index('@')
            latter = email[index: ]
            before = email[: index]
            new_before = ''
            for ch in before:
                if ch == '.': continue
                elif ch == '+': break
                else: new_before += ch
            
            return new_before + latter
        res = set()
        for email in emails:
            res.add(process_email(email))
        return len(res)
```