#include "Application.h"
#include "gtest/gtest.h"

#include "iptux/DialogPeer.h"
#include "iptux/TestHelper.h"
#include "iptux/UiCoreThread.h"

using namespace std;
using namespace iptux;

TEST(DialogPeer, Constructor) {
  Application* app = CreateApplication();

  PPalInfo pal = make_shared<PalInfo>("127.0.0.1", 2425);
  app->getCoreThread()->AttachPalToList(pal);

  GroupInfo* grpinf = app->getCoreThread()->GetPalRegularItem(pal.get());
  DialogPeer::PeerDialogEntry(app, grpinf);
  DestroyApplication(app);
}
