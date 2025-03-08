# CEfficiencyTests
Testing optimizations in C

```
//utilize short circuiting and branch prediction (slightly faster)
    if (h->y1 != horizontalYs[j])
      continue;
    if (h->x1 >= v->x1)
      continue;
    if (h->end <= v->x1)
      continue;
    if (v->y1 >= h->y1)
      continue;
    if (v->end <= h->y1)
      continue;
    thread_count++;
```

```
 //(slightly slower)
if ( h->x1 < v->x1 && h->end > v->x1 && v->y1 < h->y1 && v->end > h->y1) 
{
  thread_count++;
}

```
