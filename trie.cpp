#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mod 1000000007
string s;
struct trie_node
{
    struct trie_node *child[26];
    bool word_end;
};
struct trie_node *get_node()
{
    struct trie_node *temp=new trie_node;
    temp->word_end=false;
    for(int i=0;i<26;i++)
    temp->child[i]=NULL;
    return temp;
}
void insert(struct trie_node *root,string key)
{
  struct trie_node *crawl=root;
  for(int i=0;i<key.size();i++)
  {
      int idx=key[i]-'A';
      if(crawl->child[idx]==NULL)
      crawl->child[idx]=get_node();
      crawl=crawl->child[idx];
  }
  crawl->word_end=true;
}
int search(struct trie_node *root,int st)
{int count=0;
    struct trie_node *crawl=root;
    for(int i=st;i<s.size();i++)
    {
        int idx=s[i]-'A';
        if(crawl->child[idx]==NULL)
        break;
        crawl=crawl->child[idx];
        if(crawl->word_end)
        count++;
    }
    return (count);
}
void traversal(struct trie_node* root,int &c)
{ int c1=c;
   for(int i=0;i<26;i++)
   if(root->child[i]!=NULL)
   {   cout<<c1<<"->"<<++c<<":"<<char('A'+i)<<"\n";
       traversal(root->child[i],c);
   }
}
int32_t main() {
    int n,c=0;
    struct trie_node*root=get_node();
    cin>>s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string k;
        cin>>k;
        insert(root,k);
    }
    vector<int>ans;
    for(int i=0;i<s.size();i++)
    {
        if(search(root,i))
        ans.pb(i);
        
    }
    for(auto x:ans)
    cout<<x<<" ";
    return 0;
}
