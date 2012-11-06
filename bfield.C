void bfield(void) {
  cout << "Hi" << endl;

  const Int_t NMAX=5; // for defining
  Double_t g[NMAX];  // note g[0] = g_1 from Gubser
  Double_t s[NMAX];  // note s[0] = s_{12} from Gubser, s[1] = s_{23}, ...

  Double_t mu[NMAX]={39400.,39400.,39400.,39400.,39400.};  // note mu[0] = mu_1 from Gubser

  Double_t b[NMAX]={30.,38.,48.,62.,78.}; // ", note b[0] = b_1 from Gubser

  Double_t t=(1./8.)*2.54; // 1/8" thickness

  Double_t u[NMAX+1],v[NMAX+1];


  cout << "t = " << t << endl;

  Int_t N=1; // for looping


  for(Int_t i=0;i<N;i++) {
    g[i]=mu[i]*t/b[i];
    cout << "g[" << i << "] = " << g[i] << endl;
  }

  for(Int_t i=0;i<N-1;i++) {
    s[i]=(b[i+1]-b[i]-t)/b[i+1];
  }
  s[N-1]=0.;

  for(Int_t i=0;i<N;i++)
    cout << "s[" << i << "] = " << s[i] << endl;


  u[0]=1.;
  v[0]=1.;

  for(Int_t i=0;i<N;i++) {
    u[i+1]=(1+g[i]*s[i])*u[i]+s[i]*v[i];
    v[i+1]=g[i]*u[i]+v[i];
    cout << "u[" << i+1 << "] = " << u[i+1] << endl;
    cout << "v[" << i+1 << "] = " << v[i+1] << endl;
  }

  Double_t G=0.5*(u[N]+v[N]);

  cout << "G is " << G << endl;

}

