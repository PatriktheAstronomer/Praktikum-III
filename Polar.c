{
   TCanvas * Polar = new TCanvas("Polar","Z1",500,500);
   const Int_t n = 36; //input number of lines
   Double_t theta[n];
   Double_t E[n];
   Double_t etheta[n];
   Double_t eE[n];
   FILE* data;
   data = fopen("Polar1.txt","r"); //source name
   for(Int_t i = 0; i < n; i++){
   	fscanf(data, "%lf	%lf	%lf	%lf", &theta[i], &etheta[i], &E[i], &eE[i]);
	}
   fclose(data);
   TGraphPolar * grP1 = new TGraphPolar(n, theta, E, etheta, eE);
   grP1->SetTitle("");
   grP1->SetMarkerStyle(20);
   grP1->SetMarkerSize(2.);
   grP1->SetMarkerColor(4);
   grP1->SetLineColor(2);
   grP1->SetLineWidth(3);
   grP1->Draw("PE");
   Polar->Update();
   grP1->SetMinRadial();
   return Polar;
}
